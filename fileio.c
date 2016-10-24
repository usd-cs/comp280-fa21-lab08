/*
 * This program shows a simple example of reading in values from a file.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
	// (0) declare a FILE * variable
	FILE *infile;  // a file pointer is not a pointer like pointers to other 
				   // C types: dereferencing it doesn't make any sense!

	if(argc != 2) {
		printf("usage: %s <input.txt>\n", argv[0]);
		exit(1);
	}

	/*
	 * (1) open the file for reading and check that open succeeded 
	 *     (the file name is passed as command line arg)
	 */
	infile = fopen(argv[1], "r");   
	if (infile == NULL) { 
		printf("Error: file open %s\n", argv[1]);
		exit(1);
	}

	/*
	 * (2) read in some values from the file using fscanf
	 *     fscanf is like scanf, except that it takes a FILE *
	 *     to the file from which to read as its first argument
	 *     it returns the number of items read (or fewer on EOF or error)
	 */
	int num_students, num1, num2, ret;
	ret = fscanf(infile, "%d", &num_students); 
	if(ret == 1) {
		char name[64];

		ret = fscanf(infile, "%s%d%d", name, &num1, &num2); 
		int i = 0;
		while((i < num_students) && (ret == 3)) {  
			printf("line %d:  %10s %4d %4d\n", i, name, num1, num2);
			// read in the next line
			ret = fscanf(infile, "%s%d%d", name, &num1, &num2); 
			i++;
		}
	}

	// (3) close the file when done with it
	fclose(infile);  
	return 0;
}
