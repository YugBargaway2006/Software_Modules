FROM python:3.11-alpine

RUN apk add --no-cache docker-cli docker-cli-compose
RUN pip install docker

WORKDIR /app

COPY autoscaler/autoscaler.py .
COPY docker-compose.yml .

ENTRYPOINT ["python", "-u", "autoscaler.py"]