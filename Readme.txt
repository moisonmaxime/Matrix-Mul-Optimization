dgemm-naive
Stock - Compare with optimizations

dgemm-unroll
Loop unrolling optimization (40pts)

dgemm-tile
Cache blocking optimization (40pts)

dgemm-reorder


dgemm-chunk
Loading a chunk of the array into memory to have faster access (40pts)
To do so, the loop had to be reordered 
which is why I provided dgemm-reorder (as a benchmark)

