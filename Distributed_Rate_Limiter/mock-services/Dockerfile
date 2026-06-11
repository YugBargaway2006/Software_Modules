FROM python:3.11-alpine 

WORKDIR /app 

# Copy source file to build at runtime
COPY app.py . 

EXPOSE 5000
ENTRYPOINT [ "python" , "app.py" ]
