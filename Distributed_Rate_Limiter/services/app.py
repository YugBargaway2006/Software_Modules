from http.server import HTTPServer, BaseHTTPRequestHandler
import json 


class MockMicroservicesHandler(BaseHTTPRequestHandler):
    def do_GET(self):
        self.send_response(200)
        self.send_header('Content-Type', 'application/json')
        self.end_headers()

        # Route to individual components
        if "/payments" in self.path:
            response = {"service": "Payments Microservice", "status": "Success", "balance_processed": "$5000"}
        elif "/data" in self.path:
            response = {"service" : "Core Data Engine", "metrics" : [102, 105, 99, 101]}
        elif "/query" in self.path:
            response = {"service" : "Read-Optimized Query API", "result": "Cache Hit"}
        else:   
            response = {"service" : "Fallback Cluster Service", "message" : "Generic Landing Reached"} 

        self.wfile.write(json.dumps(response).encode('utf-8'))


if __name__ == '__main__':
    server = HTTPServer(('0.0.0.0', 5000), MockMicroservicesHandler)
    print("Mock Microservices Array listening on port 5000")
    server.serve_forever()