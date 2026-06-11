#!/bin/bash
echo "Running Distributed Rate Limiter..."

mkdir -p autoscaler config gateway/src gateway/include mock-services

if ! command -v docker &> /dev/null; then
    echo "Docker not found. Please install Docker first."
    exit 1
fi

if [ ! -f config/haproxy.cfg ]; then
    echo "Creating dummy HAProxy config..."
    touch config/haproxy.cfg
fi

echo "Setup complete. Run 'docker compose up -d --build' to start."