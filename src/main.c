#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "func.h" // Include the header file for the matrix multiplication functions
#include "data.h" // Include the header file for the data functions
#include "perf.h" // Include the header file for the performance functions

int main(int argc, char *argv[])
{
	// read n, m, k command line arguments
	int n = atoi(argv[1]); // atoi converts a string to an integer
	int m = atoi(argv[2]);
	int k = atoi(argv[3]);

	// Generate random matrices A and B
	double **A = random_matrix(m, k); // random_matrix is a function defined in data.h
	double **B = random_matrix(k, n); // fills the matrices with random values between 0 and 1

	// Allocate memory for the result matrix C
	double **C = dmalloc_2d(m, n); // dmalloc_2d is a function defined in data.h
	C = zero_matrix(m, n, C);	   // zero_matrix is a function defined in data.h

	// Perform matrix multiplication C = A * B using the library function
	double **C_lib = copy_matrix(m, n, C);						// copy_matrix is a function defined in data.h
	double time_lib = timer(matmult_lib, m, n, k, A, B, C_lib); // timer is a function defined in perf.h and matmult_lib is a function defined in func.h					// matmult_lib is a function defined in func.h
	printf("C_lib_result:\n");
	print_matrix(m, n, C_lib); // print_matrix is a function defined in data.h
	printf("Time taken by matmult_lib: %.8f seconds\n", time_lib);

	// Perform matrix multiplication C = A * B using different loop orders
	double **C_mnk = copy_matrix(m, n, C);						// copy_matrix is a function defined in data.h
	double time_mnk = timer(matmult_mnk, m, n, k, A, B, C_mnk); // timer is a function defined in perf.h and matmult_mnk is a function defined in func.h
	printf("C_mnk_result:\n");
	print_matrix(m, n, C_mnk); // print_matrix is a function defined in data.h
	printf("Time taken by matmult_mnk: %.8f seconds\n", time_mnk);

	double **C_mkn = copy_matrix(m, n, C);						// copy_matrix is a function defined in data.h
	double time_mkn = timer(matmult_mkn, m, n, k, A, B, C_mkn); // timer is a function defined in perf.h and matmult_mkn is a function defined in func.h
	printf("C_mkn_result:\n");
	print_matrix(m, n, C_mkn); // print_matrix is a function defined in data.h
	printf("Time taken by matmult_mkn: %.8f seconds\n", time_mkn);

	double **C_nkm = copy_matrix(m, n, C);						// copy_matrix is a function defined in data.h
	double time_nkm = timer(matmult_nkm, m, n, k, A, B, C_nkm); // timer is a function defined in perf.h and matmult_nkm is a function defined in func.h
	printf("C_nkm_result:\n");
	print_matrix(m, n, C_nkm); // print_matrix is a function defined in data.h
	printf("Time taken by matmult_nkm: %.8f seconds\n", time_nkm);

	double **C_nmk = copy_matrix(m, n, C);						// copy_matrix is a function defined in data.h
	double time_nmk = timer(matmult_nmk, m, n, k, A, B, C_nmk); // timer is a function defined in perf.h and matmult_nmk is a function defined in func.h
	printf("C_nmk_result:\n");
	print_matrix(m, n, C_nmk); // print_matrix is a function defined in data.h
	printf("Time taken by matmult_nmk: %.8f seconds\n", time_nmk);

	double **C_kmn = copy_matrix(m, n, C);						// copy_matrix is a function defined in data.h
	double time_kmn = timer(matmult_kmn, m, n, k, A, B, C_kmn); // timer is a function defined in perf.h and matmult_kmn is a function defined in func.h
	printf("C_kmn_result:\n");
	print_matrix(m, n, C_kmn); // print_matrix is a function defined in data.h
	printf("Time taken by matmult_kmn: %.8f seconds\n", time_kmn);

	double **C_knm = copy_matrix(m, n, C);						// copy_matrix is a function defined in data.h
	double time_knm = timer(matmult_knm, m, n, k, A, B, C_knm); // timer is a function defined in perf.h and matmult_knm is a function defined in func.h
	printf("C_knm_result:\n");
	print_matrix(m, n, C_knm); // print_matrix is a function defined in data.h
	printf("Time taken by matmult_knm: %.8f seconds\n", time_knm);

	// Free the memory allocated for the matrices
	free_2d(A);		// free_2d is a function defined in data.h
	free_2d(B);		// free_2d is a function defined in data.h
	free_2d(C);		// free_2d is a function defined in data.h
	free_2d(C_lib); // free_2d is a function defined in data.h
	free_2d(C_mnk); // free_2d is a function defined in data.h
	free_2d(C_mkn); // free_2d is a function defined in data.h
	free_2d(C_nkm); // free_2d is a function defined in data.h
	free_2d(C_nmk); // free_2d is a function defined in data.h
	free_2d(C_kmn); // free_2d is a function defined in data.h
	free_2d(C_knm); // free_2d is a function defined in data.h
}
