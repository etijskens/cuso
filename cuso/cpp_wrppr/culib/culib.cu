#include "culib.hpp"


// Kernel function to add the elements of two arrays
__global__
void add(int n, double *x, double *y, double*z)
{
  for (int i = 0; i < n; i++)
    z[i] = x[i] + y[i];
}


void 
culib_add
    ( double const* a
    , double const* b
    , double* c // a+b 
    , size_t n
    )
{
  double *cu_a, *cu_b, *cu_c;

  // Allocate Unified Memory – accessible from CPU or GPU
  cudaMallocManaged(&cu_a, n*sizeof(double));
  cudaMallocManaged(&cu_b, n*sizeof(double));
  cudaMallocManaged(&cu_c, n*sizeof(double));

  // initialize a and b arrays on the host
    for( size_t i = 0; i < n; ++i ) {
        cu_a[i] = a[i];
        cu_b[i] = b[i];
    }

 // Run kernel on 1M elements on the GPU
    add<<<1, 1>>>(n, cu_a, cu_b, cu_c);

 // Wait for GPU to finish before accessing on host
    cudaDeviceSynchronize();

    for( size_t i = 0; i < n; ++i ) {
        c[i] = cu_c[i];
    }
}