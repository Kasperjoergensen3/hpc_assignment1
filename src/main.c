#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "func.h" // Include the header file for the matrix multiplication functions
#include "data.h" // Include the header file for the data functions
#include "perf.h" // Include the header file for the performance functions

typedef void (*MatMultFunc)(int, int, int, double **, double **, double **);

int main(int argc, char *argv[])
{
	// read n, m, k and output file name from command line arguments
	int n = atoi(argv[1]); // atoi converts a string to an integer
	int m = atoi(argv[2]);
	int k = atoi(argv[3]);
	char *output_file = argv[4];

	// Open file in append mode
	FILE *file = fopen(output_file, "a");
	if (file == NULL)
	{
		perror("Error opening file");
		return 1;
	}
	// Check if file is empty (i.e., just created or truncated)
	fseek(file, 0, SEEK_END);
	if (ftell(file) == 0)
	{ // If the file is empty, write the header
		fprintf(file, "m,n,k,time_lib,time_mnk,time_mkn,time_nkm,time_nmk,time_kmn,time_knm\n");
	}
	rewind(file); // Reset file position
	fprintf(file, "%d,%d,%d", m, n, k);

	// Generate random matrices A and B
	double **A = random_matrix(m, k); // random_matrix is a function defined in data.h
	double **B = random_matrix(k, n); // fills the matrices with random values between 0 and 1

	// Allocate memory for the result matrix C
	double **C = dmalloc_2d(m, n); // dmalloc_2d is a function defined in data.h
	C = zero_matrix(m, n, C);	   // zero_matrix is a function defined in data.h

	// Perform matrix multiplication C = A * B using the library function
	double **C_lib = copy_matrix(m, n, C);					// copy_matrix is a function defined in data.h
	double time = timer(matmult_lib, m, n, k, A, B, C_lib); // timer is a function defined in perf.h and matmult_lib is a function defined in func.h
	fprintf(file, ",%.8f", time);

	// Perform matrix multiplication C = A * B using different loop orders
	MatMultFunc matmult_funcs[] = {matmult_mnk, matmult_mkn, matmult_nmk, matmult_nkm, matmult_kmn, matmult_knm}; // Array of function pointers to different matrix multiplication implementations
	int num_funcs = sizeof(matmult_funcs) / sizeof(matmult_funcs[0]);											  // Number of functions in the array
	for (int i = 0; i < num_funcs; i++)
	{
		C = zero_matrix(m, n, C); // Reset C before each multiplication
		time = timer(matmult_funcs[i], m, n, k, A, B, C);
		if (!check_matrix(m, n, C_lib, C))
		{
			perror("Error: matmult function does not match reference implementation\n");
			return 1;
		}
		fprintf(file, ",%.8f", time);
	}
	fprintf(file, "\n");

	// Close the file
	fclose(file);

	// Free the memory allocated for the matrices
	free_2d(A);		// free_2d is a function defined in data.h
	free_2d(B);		// free_2d is a function defined in data.h
	free_2d(C);		// free_2d is a function defined in data.h
	free_2d(C_lib); // free_2d is a function defined in data.h
}
