
void naive(int m, int n, float *A, float *C) {
    for( int i = 0; i < m; i++ )
        for( int k = 0; k < n; k++ )
            for( int j = 0; j < m; j++ )
                C[i+j*m] += A[i+k*m] * A[j+k*m];
}

void blockMM(int m, int n, float *A, float *C) {
    
}

// Unrolling by 4 seems to be optimal
void unrolled4(int m, int n, float *A, float *C) {
    int i,j,k;
    for(i=0; i < m; i++) {
        for(k=0; k < n-3; k+=4) {
            for(j=0; j < m; j++) {
                int index = i+j*m;
                C[index] += A[i+k*m] * A[j+k*m];
                C[index] += A[i+(k+1)*m] * A[j+(k+1)*m];
                C[index] += A[i+(k+2)*m] * A[j+(k+2)*m];
                C[index] += A[i+(k+3)*m] * A[j+(k+3)*m];
            }
        }
        for(; k<n; k++) {
            for (j=0; j < m; j++) {
                C[i+j*m] += A[i+k*m] * A[j+k*m];
            }
        }
    }
}

void dgemm(int m, int n, float *A, float *C) {
    // FILL-IN
    unrolled4(m, n, A, C);
}
