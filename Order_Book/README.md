# Jupiter: Low-Latency HFT Limit Order Book

![Language](https://img.shields.io/badge/language-C++17-blue.svg) ![Latency](https://img.shields.io/badge/latency-641ns-brightgreen.svg) ![License](https://img.shields.io/badge/license-MIT-green.svg)

**Jupiter** is a clean-room implementation of a high-frequency trading matching engine, designed for **tick-to-trade latency** and **cache locality**. It processes limit orders, executes trades and manages the order book using custom memory allocators and flat-array indexing to minimize OS overhead.

## Key Features

* **Flat-Array Storage:** Replaced standard Red-Black Trees (`std::map`) with pre-allocated `std::vector` buckets for **O(1)** order insertion and lookup.
* **Zero-Allocation Runtime:** Implemented a custom **Object Pool** to recycle `Order` objects, eliminating `malloc/free` syscalls during the trading session.
* **Zero-Copy Networking:** Raw POSIX UDP socket handling with packed binary structs for direct network-to-engine data flow.
* **Type Safety:** Strict strong-typing for Prices and Quantities to prevent mixed-unit arithmetic errors.

## Performance Benchmark

Measured on a standard consumer laptop (Linux/GCC -O3):

| Metric | Latency (Nanoseconds) |
| :--- | :--- |
| **Minimum Latency** | **641 ns** |
| Average Latency | ~4,700 ns (Includes OS Jitter and memory reallocation) |
| Throughput | ~1.5 Million Orders/sec |

*See [BENCHMARKS.md](documentations/BENCHMARKS.md) for methodology.*

## Build & Run

### Requirements
- GCC or Clang with **C++17** support  
- `bash`  
- `cmake`  
- `make`  

---

### Script-Based Workflow (Recommended)

The project uses the `Order_Book.sh` script to manage the complete lifecycle: cleaning, configuring, building, testing, and running the application.

```bash
# Full pipeline: clean → configure → build → test → run
./Order_Book.sh

# Configure → build → run
./Order_Book.sh --build

# Clean build artifacts only
./Order_Book.sh --clean

# Clean → configure → build → run
./Order_Book.sh --clean_build

# Configure → build → test
./Order_Book.sh --test

```

---

### Additional documentations for system understanding

*See [ARCHITECTURE.md](documentations/ARCHITECTURE.md) for methodology and structure choices.*

*See [PROTOCOLS.md](documentations/PROTOCOLS.md) for UDP data packet protocols and compression.*

*See [TODO.md](documentations/TODO.md) for future improvements.*
