#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "io.h"
#include "data.h"

int main(int argc, char *argv[])
{
	io();
	data();
	if (argc != 3)
	{
		printf("Usage: %s <num1> <num2>\n", argv[0]);
		return 1; // Return an error code
	}

	// Convert arguments to integers
	int num1 = atoi(argv[1]);
	int num2 = atoi(argv[2]);
	int sum = num1 + num2;

	// Output the result of some operation (e.g., addition)
	printf("The sum of %d and %d is %d\n", num1, num2, sum);

	// Write the data to a CSV file
	const char *filename = "outputs/output.csv";
	write_to_csv(filename, num1, num2, sum);
	write_to_csv(filename, num1, num2, sum);

	printf("Data written to %s\n", filename);
	return (EXIT_SUCCESS);
}
