#include <stdio.h>
#include <stdlib.h>
#include "data.h"

void data(void)
{
    printf("Working on data. test2\n");
};

void write_to_csv(const char *filename, int num1, int num2, int sum)
{
    FILE *file = fopen(filename, "w"); // Open file for writing
    if (file == NULL)
    {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    // Write CSV header
    fprintf(file, "Number1,Number2,Sum\n");

    // Write data
    fprintf(file, "%d,%d,%d\n", num1, num2, sum);

    fclose(file); // Close the file
};