
// OPTIMIZED
//
// - Runs 4 multiplications at once                             (Aka unrolling - 40pts)
//      ^ Unrolling by 4 seems to be optimal (vs 2, 3, 5, 8, 16)
// - Switched i and j to optimize the memory fetching           (Aka reordering - 40pts)
//      ^ this takes advantage of the locality (A[i+j*m] is closer to A[(i+1)+j*m] than A[i+(j+1)*m]
//      ^ More often in the same block == faster load time
// - Load 4 rows of matrix into B to reuse as a smaller array   (Aka load chunk - 40pts)
//      ^ reduces memory fetching times

#include <string.h>
void dgemm(int m, int n, float *A, float *C) {
    int i,j,k;
    float B[4*m];
    for(k=0; k<n-3; k+=4) {
        memcpy(B, &A[k*m], 4*m*sizeof(float));
        for(j=0; j<m; j++) {
            for(i=0; i<m; i++) {
                int index = i+j*m;
                C[index] += B[i] * B[j];
                C[index] += B[i+1*m] * B[j+1*m];
                C[index] += B[i+2*m] * B[j+2*m];
                C[index] += B[i+3*m] * B[j+3*m];
            }
        }
    }
    for(; k<n; k++) {
        memcpy(B, &A[k*m], m*sizeof(float));
        for (j=0; j < m; j++) {
            for (i=0; i < m; i++) {
                C[i+j*m] += B[i] * B[j];
            }
        }
    }
}
