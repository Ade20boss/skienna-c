
# ARCHITECTURE: Hash Tables (O(1) Lookup)

**The Core Principle**
A hash table trades memory for speed. Instead of iterating through data (O(n)) or dividing it (O(logn)), it uses a mathematical calculation to instantly map a key to a physical memory address (O(1)).

**The Three Components**
1. **The Backing Array:** A contiguous block of memory allocated on the heap (using `calloc` to ensure empty slots are initialized to `NULL` or `0`).
2. **The Hash Function:** The mathematical engine that converts a key(like a string) into a massive integer.
3. **The Modulo Router:** The operation (`Hash % capacity`) that forces the massive integer to fit within the bounds of the backing array.

**Time Complexity**
- **Best / Average Case:** O(1) (Instant lookup)
- **Worst Case:** O(n) (Occurs if the hash function is terrible and maps every key to the exact same index, forcing the system to search sequentially).



