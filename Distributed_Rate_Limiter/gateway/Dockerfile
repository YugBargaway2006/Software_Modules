# Build Env
FROM ubuntu:24.04 AS builder

RUN apt-get update && apt-get install -y \
    build-essential \
    cmake \
    git \
    libssl-dev \
    libhiredis-dev \
    && rm -rf /var/lib/apt/lists/* 

WORKDIR /build 
COPY . . 

RUN mkdir build && cd build && \
    cmake -DCMAKE_BUILD_TYPE=Release .. && \
    make -j$(nproc)


# Production Runtime
FROM ubuntu:24.04

RUN apt-get update && apt-get install -y \
    libssl3 \
    libhiredis-dev \  
    ca-certificates \
    && rm -rf /var/lib/apt/lists/* 

WORKDIR /app 
COPY --from=builder /build/build/gateway_bin .

EXPOSE 8000
ENTRYPOINT [ "./gateway_bin" ]