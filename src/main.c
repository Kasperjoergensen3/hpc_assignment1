#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "func.h" // Include the header file for the matrix multiplication functions
#include "data.h" // Include the header file for the data functions

int main(int argc, char *argv[])
{
	// read n, m, k from command line arguments
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
	double **C_lib_result = copy_matrix(m, n, C); // copy_matrix is a function defined in data.h
	matmult_lib(m, n, k, A, B, C_lib_result);	  // matmult_lib is a function defined in func.h
	printf("C_lib_result:\n");
	print_matrix(m, n, C_lib_result); // print_matrix is a function defined in data.h

	// Perform matrix multiplication C = A * B using different loop orders
}
