# System Architecture

## 1. The Core: Flat-Array Order Book
Traditional order books use `std::map` (RB-Trees) to store orders sorted by price. This results in **O(log N)** complexity and poor cache locality due to pointer chasing.

**Jupiter** utilizes a **Flat-Array** approach (Direct Indexing):
* **Concept:** Prices are converted to integer "Ticks" (e.g., $100.05 -> 10005).
* **Storage:** A `std::vector<std::list<Order*>>` where the index `i` corresponds directly to price `i`.
* **Impact:**
    * **Lookup:** **O(1)** (Direct Array Access).
    * **Insertion:** **O(1)**.
    * **Deletion:** **O(1)** (via Lookup Table).

## 2. Memory Management: The Object Pool
In high frequency operations, `new` and `delete` are too slow (System Calls).
Jupiter uses a pre-allocated `OrderPool`:
* At startup, 100,000 `Order` objects are allocated on the Heap.
* A `std::vector` acts as a stack of "free" pointers.
* **Acquire:** Pop a pointer from the stack.
* **Release:** Push the pointer back to the stack.
* **Result:** Zero runtime memory fragmentation and zero allocation latency.

## 3. Network Gateway
* **Protocol:** UDP Unicast (Simulated Direct Feed).
* **Decoding:** The receiver reads raw bytes into a packed struct (`OrderMessage`).
* **Endianness:** Handles Network-to-Host byte swapping (`ntohl`) for cross-architecture compatibility.