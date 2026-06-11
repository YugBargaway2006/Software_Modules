# Performance Benchmarks

## Methodology
Benchmarks measure the **Engine Processing Latency**. This is defined as the time delta between:
1.  **T0:** Packet decoded and fields extracted.
2.  **T1:** Order processed, matched, and committed to the book/log.

Timestamps are captured using `std::chrono::high_resolution_clock`.

## Test Environment
* **Compiler:** g++ 9.4.0 with `-O3` optimization.
* **OS:** Linux (Ubuntu 22.04 via dual boot with Windows 11).
* **Network:** Localhost Loopback (127.0.0.1) via UDP.

## Results Analysis

| Statistic | Latency (ns) | Notes |
| :--- | :--- | :--- |
| **Min** | **641** | **Hot Cache Path.** Represents the true theoretical speed of the logic without OS interrupts. |
| **Avg** | **2,741** | Affected by OS context switching between the Simulator process and Engine process on the same machine. |
| **Max** | **86,376** | Outlier caused by initial page faults or OS scheduling (Context Switch). |

**Conclusion:**
The logic executes in sub-microsecond time (~0.6 μs). The variance in Average Latency is attributed to the "Noisy Neighbor" effect of running the Simulator on the same CPU core as the Engine. In a production environment with `isolcpus`, latency would converge toward the Minimum.