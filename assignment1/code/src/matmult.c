#include <cblas.h>
#include <math.h>	// For fmin
#include <stdlib.h> // For malloc/free
#include "matmult.h"

/**
 * @brief Performs matrix multiplication using an optimized BLAS library (cblas_dgemm).
 *
 * Computes C = A * B using the CBLAS library for optimal performance.
 */
void matmult_lib(int M, int N, int K, double **A, double **B, double **C)
{
	cblas_dgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans,
				M, N, K, 1.0,
				*A, K,		 // A matrix and leading dimension
				*B, N,		 // B matrix and leading dimension
				0.0, *C, N); // C matrix and leading dimension
}

/**
 * @brief Calls matmult_mnk as the default naive matrix multiplication.
 */
void matmult_nat(int M, int N, int K, double **A, double **B, double **C)
{
	matmult_mnk(M, N, K, A, B, C);
}

/**
 * @brief Matrix multiplication with m-n-k loop ordering.
 */
void matmult_mnk(int M, int N, int K, double **A, double **B, double **C)
{
	for (int m = 0; m < M; m++)
		for (int n = 0; n < N; n++)
			for (int k = 0; k < K; k++)
				C[m][n] += A[m][k] * B[k][n];
}

/**
 * @brief Matrix multiplication with m-k-n loop ordering.
 */
void matmult_mkn(int M, int N, int K, double **A, double **B, double **C)
{
	for (int m = 0; m < M; m++)
		for (int k = 0; k < K; k++)
			for (int n = 0; n < N; n++)
				C[m][n] += A[m][k] * B[k][n];
}

/**
 * @brief Matrix multiplication with n-k-m loop ordering.
 */
void matmult_nkm(int M, int N, int K, double **A, double **B, double **C)
{
	for (int n = 0; n < N; n++)
		for (int k = 0; k < K; k++)
			for (int m = 0; m < M; m++)
				C[m][n] += A[m][k] * B[k][n];
}

/**
 * @brief Matrix multiplication with k-m-n loop ordering.
 */
void matmult_kmn(int M, int N, int K, double **A, double **B, double **C)
{
	for (int k = 0; k < K; k++)
		for (int m = 0; m < M; m++)
			for (int n = 0; n < N; n++)
				C[m][n] += A[m][k] * B[k][n];
}

/**
 * @brief Matrix multiplication with k-n-m loop ordering.
 */
void matmult_knm(int M, int N, int K, double **A, double **B, double **C)
{
	for (int k = 0; k < K; k++)
		for (int n = 0; n < N; n++)
			for (int m = 0; m < M; m++)
				C[m][n] += A[m][k] * B[k][n];
}

/**
 * @brief Matrix multiplication with n-m-k loop ordering.
 */
void matmult_nmk(int M, int N, int K, double **A, double **B, double **C)
{
	for (int n = 0; n < N; n++)
		for (int m = 0; m < M; m++)
			for (int k = 0; k < K; k++)
				C[m][n] += A[m][k] * B[k][n];
}

/**
 * @brief Blocked matrix multiplication for cache optimization.
 *
 * Uses a tiling approach with a given block size `bs`.
 */
void matmult_blk(int M, int N, int K, double **A, double **B, double **C, int bs)
{
	for (int m0 = 0; m0 < M; m0 += bs)
		for (int k0 = 0; k0 < K; k0 += bs)
			for (int n0 = 0; n0 < N; n0 += bs)
				for (int m = m0; m < fmin(m0 + bs, M); m++)
					for (int k = k0; k < fmin(k0 + bs, K); k++)
						for (int n = n0; n < fmin(n0 + bs, N); n++)
							C[m][n] += A[m][k] * B[k][n];
}
