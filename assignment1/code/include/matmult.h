#ifndef MATMULT_H
#define MATMULT_H

#include <stddef.h> // For size_t

/**
 * @file func.h
 * @brief Matrix multiplication function declarations.
 *
 * This header defines multiple matrix multiplication functions,
 * including a library-based method, naive implementation,
 * and various loop orderings for performance evaluation.
 */

/**
 * @brief Performs matrix multiplication using an external optimized library.
 *
 * @param m Number of rows in matrix A.
 * @param n Number of columns in matrix B.
 * @param k Number of columns in matrix A (or rows in matrix B).
 * @param A Pointer to matrix A.
 * @param B Pointer to matrix B.
 * @param C Pointer to matrix C (result matrix).
 */
void matmult_lib(int m, int n, int k, double **A, double **B, double **C);

/**
 * @brief Naive implementation of matrix multiplication (row-major).
 */
void matmult_nat(int m, int n, int k, double **A, double **B, double **C);

/**
 * @brief Matrix multiplication with different loop orderings.
 */
void matmult_mnk(int m, int n, int k, double **A, double **B, double **C);
void matmult_mkn(int m, int n, int k, double **A, double **B, double **C);
void matmult_nkm(int m, int n, int k, double **A, double **B, double **C);
void matmult_kmn(int m, int n, int k, double **A, double **B, double **C);
void matmult_knm(int m, int n, int k, double **A, double **B, double **C);
void matmult_nmk(int m, int n, int k, double **A, double **B, double **C);

/**
 * @brief Blocked matrix multiplication for cache efficiency.
 *
 * @param bs Block size for tiling.
 */
void matmult_blk(int m, int n, int k, double **A, double **B, double **C, int bs);

#endif // FUNC_H
