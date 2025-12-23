# Future Improvements

- [ ] **Kernel Bypass:** Port the `MarketDataReceiver` to use **DPDK** or **Solarflare OpenOnload** to skip the Linux Kernel stack.
- [ ] **Lock-Free Queue:** Implement a Single-Producer/Single-Consumer (SPSC) Ring Buffer to decouple the Network Thread from the Matching Engine Thread.
- [ ] **TCP Recovery:** Implement a snapshot mechanism to rebuild the book state if packets are dropped.
- [ ] **Multi-Core Scaling:** Pin the Engine thread to a dedicated CPU core (`isolcpus`) to reduce context switching jitter.