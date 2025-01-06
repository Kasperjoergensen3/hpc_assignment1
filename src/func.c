
#include <math.h>
#if defined(__MACH__) && defined(__APPLE__)
#include <Accelerate/Accelerate.h>
#else
#include <cblas.h>
#endif
#include "data.h"
#include "func.h"

// matrix multiplication of two m x k and k x n matrices using cblas_dgemm
void matmult_lib(int M, int N, int K, double **A, double **B, double **C)
{
	// parameters for cblas_dgemm so that it results in C = A * B
	int alpha = 1.0;
	int beta = 0.0;
	// cblas_dgemm is a function from the BLAS library that performs matrix multiplication of the form C = alpha * A * B + beta * C
	cblas_dgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans, // row-major order, A is not transposed, B is not transposed
				M, N, K, alpha,							   // dimensions and alpha
				*A, K,									   // A and leading dimension of A
				*B, N,									   // B and leading dimension of B
				beta, *C, N								   // beta, C and leading dimension of C
	);
}

// Order of loops for matrix multiplication
typedef enum
{
	MNK,
	MKN,
	NMK,
	NKM,
	KMN,
	KNM
} Order;

// matrix multiplication of two m x k and k x n matrices using different orders of loops
// assumes that C is initialized to zero
void matmult(int M, int N, int K, double **A, double **B, double **C, Order order)
{
	// Loop orders
	switch (order)
	{
	case MNK: // natural ordering
		for (int m = 0; m < M; m++)
			for (int n = 0; n < N; n++)
				for (int k = 0; k < K; k++)
					C[m][n] += A[m][k] * B[k][n];
		break;
	case MKN:
		for (int m = 0; m < M; m++)
			for (int k = 0; k < K; k++)
				for (int n = 0; n < N; n++)
					C[m][n] += A[m][k] * B[k][n];
		break;
	case NMK:
		for (int n = 0; n < N; n++)
			for (int m = 0; m < M; m++)
				for (int k = 0; k < K; k++)
					C[m][n] += A[m][k] * B[k][n];
		break;
	case NKM:
		for (int n = 0; n < N; n++)
			for (int k = 0; k < K; k++)
				for (int m = 0; m < M; m++)
					C[m][n] += A[m][k] * B[k][n];
		break;
	case KMN:
		for (int k = 0; k < K; k++)
			for (int m = 0; m < M; m++)
				for (int n = 0; n < N; n++)
					C[m][n] += A[m][k] * B[k][n];
		break;
	case KNM:
		for (int k = 0; k < K; k++)
			for (int n = 0; n < N; n++)
				for (int m = 0; m < M; m++)
					C[m][n] += A[m][k] * B[k][n];
		break;
	}
}

// Macro to define wrapper functions
#define DEFINE_MATMULT_WRAPPER(NAME, ORDER) \
	void NAME(int M, int N, int K, double **A, double **B, double **C) { matmult(M, N, K, A, B, C, ORDER); }

// Define all wrapper functions
DEFINE_MATMULT_WRAPPER(matmult_mnk, MNK)
DEFINE_MATMULT_WRAPPER(matmult_mkn, MKN)
DEFINE_MATMULT_WRAPPER(matmult_nmk, NMK)
DEFINE_MATMULT_WRAPPER(matmult_nkm, NKM)
DEFINE_MATMULT_WRAPPER(matmult_kmn, KMN)
DEFINE_MATMULT_WRAPPER(matmult_knm, KNM)

// Blocked matrix multiplication
// assumes that C is initialized to zero
void matmult_blk(int M, int N, int K, double **A, double **B, double **C, int bs)
{
	// Blocked matrix multiplication (MKN ordering)
	for (int m0 = 0; m0 < M; m0 += bs)
		for (int k0 = 0; k0 < K; k0 += bs)
			for (int n0 = 0; n0 < N; n0 += bs)
				for (int m = m0; m < fmin(m0 + bs, M); m++)
					for (int k = k0; k < fmin(k0 + bs, K); k++)
						for (int n = n0; n < fmin(n0 + bs, N); n++)
							C[m][n] += A[m][k] * B[k][n];
}