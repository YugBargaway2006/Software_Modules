import docker
import time
import subprocess


# Global Configuration
PROJECT_NAME = "distributed_rate_limiter"
SERVICE_NAME = "cpp-gateway"
MAX_NODES = 5
MIN_NODES = 1
SCALE_UP_CPU = 80   
SCALE_DOWN_CPU = 20
CHECK_INTERVAL = 5    


client = docker.from_env()


def get_active_gateways():
    filters = {"label": [f"com.docker.compose.project={PROJECT_NAME}", f"com.docker.compose.service={SERVICE_NAME}"]}
    return client.containers.list(filters=filters)


def get_cpu_usage(container):
    try:
        raw_stat = subprocess.check_output(
            ['docker', 'stats', '--no-stream', '--format', '{{.CPUPerc}}', container.name]
        ).decode('utf-8').strip()
        return float(raw_stat.replace('%', ''))
    except Exception:
        return 0.0


def scale_cluster(target_replicas):
    print(f"SCALING EVENT: Adjusting {SERVICE_NAME} to {target_replicas} nodes...")
    subprocess.run([
        "docker", "compose", 
        "--project-name", PROJECT_NAME,
        "up", "-d", 
        "--scale", f"{SERVICE_NAME}={target_replicas}", 
        "--no-recreate"
    ])
    print("Scaling complete. Cooling down for 10 seconds...")
    time.sleep(10)


def run_autoscaler_loop():
    print("Containerized Autoscaler Booted. Monitoring metrics...")
    while True:
        gateways = get_active_gateways()
        current_nodes = len(gateways)
        
        if current_nodes == 0:
            print("No gateway nodes found. Waiting...")
            time.sleep(CHECK_INTERVAL)
            continue

        total_cpu = sum(get_cpu_usage(gw) for gw in gateways)
        avg_cpu = total_cpu / current_nodes
        print(f"Nodes: {current_nodes} | Cluster Avg CPU: {avg_cpu:.2f}%")

        if avg_cpu > SCALE_UP_CPU and current_nodes < MAX_NODES:
            print(f"HIGH LOAD ({avg_cpu:.2f}% > {SCALE_UP_CPU}%). Scaling UP!")
            scale_cluster(current_nodes + 1)
        elif avg_cpu < SCALE_DOWN_CPU and current_nodes > MIN_NODES:
            print(f"LOW LOAD ({avg_cpu:.2f}% < {SCALE_DOWN_CPU}%). Scaling DOWN!")
            scale_cluster(current_nodes - 1)
            
        time.sleep(CHECK_INTERVAL)



if __name__ == "__main__":
    run_autoscaler_loop()