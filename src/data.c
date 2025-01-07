#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "data.h"

// allocate a double-prec m x n matri
double **dmalloc_2d(int m, int n)
{
    if (m <= 0 || n <= 0)
        return NULL;
    double **A = malloc(m * sizeof(double *));
    if (A == NULL)
        return NULL;
    A[0] = malloc(m * n * sizeof(double));
    if (A[0] == NULL)
    {
        free(A);
        return NULL;
    }
    for (int i = 1; i < m; i++)
        A[i] = A[0] + i * n;
    return A;
}

// de-allocting memory, allocated with
void free_2d(double **A)
{
    free(A[0]);
    free(A);
}

// make copy of a matrix
double **copy_matrix(int m, int n, double **A)
{
    double **B = dmalloc_2d(m, n);
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            B[i][j] = A[i][j];
        }
    }
    return B;
}

// zero out a matrix
double **zero_matrix(int m, int n, double **A)
{
    for (int i = 0; i < m * n; i++)
    {
        A[0][i] = 0;
    }
    return A;
}

// Generates a random m x n matrix in [0,1]
double **random_matrix(int m, int n)
{
    // Use dmalloc_2d to allocate the matrix
    double **M = dmalloc_2d(m, n);
    if (M == NULL)
        return NULL;

    // Fill with random numbers in [0,1]
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            M[i][j] = (double)rand() / RAND_MAX;
        }
    }
    return M;
}

// Generates a random vector of length n in [0,1]
double *random_vector(int n)
{
    double *v = malloc(n * sizeof(double));
    if (v == NULL)
        return NULL;

    // Fill with random numbers in [0,1]
    for (int i = 0; i < n; i++)
    {
        v[i] = (double)rand() / RAND_MAX;
    }
    return v;
}

// print a double-prec m x n matrix
void print_matrix(int m, int n, double **A)
{
    int i, j;
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
            printf("%lf\t", A[i][j]);
        printf("\n");
    }
}

// print a double-prec vector
void print_vector(int n, double *v)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%lf\n", v[i]);
}
