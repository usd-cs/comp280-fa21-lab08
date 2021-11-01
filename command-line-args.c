/**
 * An example of command line arguments in C
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Simple program that gets information about a student from the command line
 * arguments.
 *
 * @param argc A count of the number of command line arguments, the executable 
 *       name (command) is included so argc is at least 1 for every program
 * @param argv An array of strings, there is one string for each command line arg
 */
int main(int argc, char *argv[]) {

	// Print out each of the command line arguments
	for (int i = 0; i < argc; i++) {
		printf("Command line arg %d: %s\n", i, argv[i]);
	}
	printf("\n");

	// It's good practice to check that the expected number of arguments were
	// given when the program was run. If not, a "usage" message is printed
	// and the program exits before trying to do anything else.
	if (argc != 5) {
		printf("usage: %s <name> <id in hexadecimal> <age> <gpa>\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	// The strtoX (where X is l, ll, or d) are used to convert strings to
	// numeric types.
	
	long int id = strtol(argv[2], NULL, 16);
	double gpa = strtod(argv[4], NULL);

	// age doesn't need to be a long so we'll cast it to a regular int
	int age = (int)strtol(argv[3], NULL, 10);

	// Check that they didn't enter a negative age!
	if (age < 0) {
		printf("Invalid age entered!\n");
		exit(EXIT_FAILURE);
	}

	printf("Student info:");
	printf("\tName: %s\n", argv[1]);
	printf("\tID: %ld\n", id);
	printf("\tAge: %d\n", age);
	printf("\tGPA: %f\n", gpa);

	return 0;
}
