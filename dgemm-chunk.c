
// Copy a chunk in memory to keep reusing + Reordering (because needed) - 40pts

#include <string.h>
void dgemm(int m, int n, float *A, float *C) {
    float B[m];
    for (int k = 0; k<n; k++) {
        memmove(B, &A[k*m], m*sizeof(float));
        for (int j = 0; j<m; j++) {
            for (int i = 0; i<m; i++) {
                C[i+j*m] += B[i] * B[j];
            }
        }
    }
}
