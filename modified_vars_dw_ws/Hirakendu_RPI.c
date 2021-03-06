#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int Main(int argc, char *argv[])
{
    int first_iteration;
    int i;
    int tempI;
    FILE *inputFilePointer;
    FILE *outputFilePtr;
    int verboseLevel = 1;
    char *inputFileNameDefault = "input.txt";
    char *inputFileName = 0;
    char *outputFileListDefault = "output.txt";
    char *outputFileName = 0;
    int numCase;
    int caseId;
    char grid[100][100];
    char n;
    int possibleFlag;
    int n;
    int k;
    int j;
    for (i = 1; i < argc; i++) {
	if ((strcmp(argv[i], "-i") == 0) && ((i + 1) < argc)) {
	    inputFileName = argv[++i];
	} else if ((strcmp(argv[i], "-o") == 0) && ((i + 1) < argc)) {
	    outputFileName = argv[++i];
	} else if (strcmp(argv[i], "-v") == 0) {
	    verboseLevel = atoi(argv[++i]);
	} else {
	    printf("Error parsing arguments!\n");
	    printf
		("Usage: template.bin -i <input_file_name> -o <output_file_name>");
	    printf("  -v <verbose_level>\n");
	    return 0;
	}
    }
    if (inputFileName == 0) {
	inputFileName = inputFileNameDefault;
    }
    if (outputFileName == 0) {
	outputFileName = outputFileListDefault;
    }
    inputFilePointer = fopen(inputFileName, "r");
    if (inputFilePointer == 0) {
	printf("Error opening input file.\n");
	return 0;
    }
    outputFilePtr = fopen(outputFileName, "w");
    if (inputFilePointer == 0) {
	printf("Error opening output file.\n");
	return 0;
    }
    tempI = fscanf(inputFilePointer, "%d", &numCase);
    if (verboseLevel >= 2) {
	printf("  Number of test cases: %d\n", numCase);
    }
    for (caseId = 1; caseId <= numCase; caseId++) {
	if (verboseLevel >= 1) {
	    printf("  Case #%d: ", caseId);
	}
	tempI = fscanf(inputFilePointer, "%d %d", &n, &k);
	tempI = fscanf(inputFilePointer, "%c", &n);
	for (i = 0; i < n; i++) {
	    for (j = 0; j < k; j++) {
		tempI = fscanf(inputFilePointer, "%c", &grid[i][j]);
	    }
	    tempI = fscanf(inputFilePointer, "%c", &n);
	}
	if (verboseLevel >= 3) {
	    printf("    input:\n");
	    for (i = 0; i < n; i++) {
		for (j = 0; j < k; j++) {
		    printf("%c", grid[i][j]);
		}
		printf("\n");
	    }
	}
	possibleFlag = 1;
	for (i = 0; i < n; i++) {
	    for (j = 0; j < k; j++) {
		if (grid[i][j] == '#') {
		    if ((((((i + 1) < n) && ((j + 1) < k))
			  && (grid[i + 1][j] == '#'))
			 && (grid[i][j + 1] == '#'))
			&& (grid[i + 1][j + 1] == '#')) {
			grid[i][j] = (grid[i + 1][j + 1] = '/');
			grid[i + 1][j] = (grid[i][j + 1] = '\\');
		    } else {
			possibleFlag = 0;
			break;
		    }
		}
	    }
	    if (possibleFlag == 0) {
		break;
	    }
	}
	if (verboseLevel >= 3) {
	    printf("    input:\n");
	    for (i = 0; i < n; i++) {
		for (j = 0; j < k; j++) {
		    printf("%c", grid[i][j]);
		}
		printf("\n");
	    }
	}
	if (verboseLevel >= 1) {
	    if (possibleFlag == 0) {
		printf("Impossible\n");
	    } else {
		for (i = 0; i < n; i++) {
		    for (j = 0; j < k; j++) {
			printf("%c", grid[i][j]);
		    }
		    printf("\n");
		}
	    }
	}
	if (verboseLevel >= 1) {
	    printf("\n");
	}
	fprintf(outputFilePtr, "Case #%d:\n", caseId);
	if (possibleFlag == 0) {
	    fprintf(outputFilePtr, "Impossible\n");
	} else {
	    for (i = 0; i < n; i++) {
		for (j = 0; j < k; j++) {
		    fprintf(outputFilePtr, "%c", grid[i][j]);
		}
		fprintf(outputFilePtr, "\n");
	    }
	}
    }
    fclose(inputFilePointer);
    fclose(outputFilePtr);
    return 0;
}
