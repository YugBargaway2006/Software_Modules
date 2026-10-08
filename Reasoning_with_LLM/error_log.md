1. I am facing one error, when I increase max token limit to 500, it gives the following, 
[W1007 22:33:47.937893272 CUDACachingAllocator.cpp:3934] memory allocation failed with OOM on device 0 while trying to allocate 92274688 bytes (free: 122552320, total: 6302138368).

Ans: KV Caching will be implemented to solve, first changing the complete logic to sequential execution of each token.


2. The stream of text is not stopping even after reaching endoftext
Ans: Added break signal for that specific token


3. torch.compile very slow:
Tested but skipped in the final implementation because compilation
introduced significant startup latency on the RTX 4050. KV caching
was retained because it is the key algorithmic optimization for
autoregressive generation.

4. Text around answer 3. Not able to use RLVR in this type of response
Ans: Added a fallback regex to extract the last number from the response.