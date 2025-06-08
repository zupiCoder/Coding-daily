#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_ROW 100
#define MAX_STRING 100
#define MAX_CHAR 110

int main(int argc, char** argv) {

	char *inputName = argv[1];
	char *outputName = argv[2];
	int m = atoi(argv[3]);

	char cols[m+1][MAX_CHAR]; int colsSize = 0;
	int colIndex[m+1];

	for(int i = 0; i < m; i++) colIndex[i] = -1;

	for(int i = 4; i < argc; i++) {
		strcpy(cols[i-4], argv[i]);
		colsSize++;
	}
	FILE* input = fopen(inputName, "r");
	FILE* output = fopen(outputName, "w");

	char buffer[MAX_CHAR * MAX_STRING];
	char tempCol[MAX_CHAR]; int ix = 0;
	fgets(buffer, MAX_CHAR * MAX_STRING, input);

	int tempIndex = 0;

	for(int i = 0; i < strlen(buffer); i++) {
		char curr = buffer[i];

		if(curr == ' ' || i == (strlen(buffer) - 1)) {
			tempCol[ix] = '\0';

			for(int j = 0; j < colsSize; j++) {
				if(strcmp(tempCol, cols[j]) == 0) colIndex[j] = tempIndex;
			}

			tempCol[0] = '\0';
			ix = 0;
			tempIndex++;
			continue;
		}
		tempCol[ix++] = curr;
	}

	fprintf(output,"%s", cols[0]);
	for(int i = 1; i < colsSize; i++) {
		fprintf(output, ",%s", cols[i]);
	}
	fprintf(output, "\n");

	char colElements[colsSize][MAX_CHAR];

	ix = 0;
	tempIndex = 0;

	while(fgets(buffer, MAX_CHAR * MAX_STRING, input) != NULL) {
		for(int x = 0; x < strlen(buffer); x++) {
			char curr = buffer[x];

			if(curr == ' ' || x == (strlen(buffer) - 1)) {
				tempCol[ix] = '\0';

				for(int j = 0; j < colsSize; j++) {
					if(tempIndex == colIndex[j]) {
						strcpy(colElements[j], tempCol);
					}
				}

				tempCol[0] = '\0';
				ix = 0;
				tempIndex++;
				continue;
			}
			tempCol[ix++] = curr;
		}
		tempCol[0] = '\0';
		tempIndex = 0;
		ix = 0;

		fprintf(output,"%s", colElements[0]);
		for(int i = 1; i < colsSize; i++) {
			fprintf(output, ",%s", colElements[i]);
		}
		fprintf(output, "\n");
	}
	fclose(input);
	fclose(output);

	return 0;
}