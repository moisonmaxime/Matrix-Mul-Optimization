
// Cache blocking - 40 pts

void dgemm(int m, int n, float *A, float *C) {
    int i,j,k;
    
    for (i = 0; i<m-1; i+=2) {
        for (k = 0; k<n; k++) {
            for (j = 0; j<m-1; j+=2) {
                C[i+j*m] += A[i+k*m] * A[j+k*m];
                C[i+1+j*m] += A[i+1+k*m] * A[j+k*m];
                C[i+(j+1)*m] += A[i+k*m] * A[j+1+k*m];
                C[i+1+(j+1)*m] += A[i+1+k*m] * A[j+1+k*m];
            }
            for (; j< m; j++) { // A
                C[i+j*m] += A[i+k*m] * A[j+k*m];
                C[i+1+j*m] += A[i+1+k*m] * A[j+k*m];
            }
        }
    }
    for (; i<m; i++) {
        for (k = 0; k<n; k++) {
            for (int j = 0; j < m-1; j+=2) { // B
                C[i+j*m] += A[i+k*m] * A[j+k*m];
                C[i+(j+1)*m] += A[i+k*m] * A[j+1+k*m];
            }
            for (; j< m; j++) { // C
                C[i+j*m] += A[i+k*m] * A[j+k*m];
            }
        }
    }
}
