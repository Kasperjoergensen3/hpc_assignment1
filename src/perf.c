#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "data.h"
#include "perf.h"

// function timer
double timer(void (*func)(int, int, int, double **, double **, double **), int m, int n, int k, double **A, double **B, double **C)
{
    double time = 0;
    double repeat_until = 5; // repeat the function until this time is reached
    int repetitions = 0;     // number of repetitions
    while (time / CLOCKS_PER_SEC < repeat_until)
    {
        repetitions++;            // increment the repetitions counter
        C = zero_matrix(m, n, C); // zero_matrix is a function defined in data.h
        clock_t start = clock();  // start the timer
        func(m, n, k, A, B, C);   // call the function to be timed. Result is stored in C
        clock_t end = clock();    // end the timer
        time += end - start;      // calculate the time taken (in clock ticks)
    }
    return time / CLOCKS_PER_SEC / repetitions; // return the average time taken
}

// check if two matrices are equal
int check_matrix(int m, int n, double **A, double **B)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (fabs(A[i][j] - B[i][j]) > 1e-6)
            {
                return 0;
            }
        }
    }
    return 1;
}
