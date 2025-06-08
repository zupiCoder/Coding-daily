#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_STRING 100
#define MAX_CHAR 110

int main(int argc, char** argv) {

    char* inputName = argv[1];
    char* outputName = argv[2];
    char* col = argv[3];

    FILE* input = fopen(inputName, "r");
    FILE* output = fopen(outputName, "w");

    int MAX_SIZE = MAX_CHAR * MAX_STRING;

    char buffer[MAX_SIZE];
    char tempCol[MAX_CHAR];
    char colElements[MAX_STRING][MAX_CHAR];
    int ages[MAX_STRING];

    int ind = 0;
    int tempColIndex = 0;
    int colIndex = 0;
    int ageIndex = 0;

    char ageCol[] = "starost";

    fgets(buffer, MAX_SIZE, input);

    for(int i = 0; i < strlen(buffer); i++) {
        if(buffer[i] == ' ' || i == (strlen(buffer) - 1)) {
            tempCol[ind] = '\0';
            if(strcmp(ageCol, tempCol) == 0) ageIndex = tempColIndex;

            if(strcmp(col, tempCol) == 0) colIndex = tempColIndex;    
            
            tempCol[0] = '\0';
            ind = 0;
            tempColIndex++;
            continue;
        }
        tempCol[ind++] = buffer[i];
    }

    int index = 0;
    int rowIndex = 0;
    tempCol[0] = '\0';
    ind = 0;

    while(fgets(buffer, MAX_SIZE, input) != NULL) {

        for(int i = 0; i < strlen(buffer); i++) {
            if(buffer[i] == ' ' || i == (strlen(buffer) - 1)) {
                tempCol[ind] = '\0';
                
                if(index == ageIndex) {
                    ages[rowIndex] = atoi(tempCol);
                }

                if(index == colIndex) {
                    strcpy(colElements[rowIndex], tempCol);
                }

                tempCol[0] = '\0';
                ind = 0;
                index++;
                continue;
            }
            tempCol[ind++] = buffer[i];
        }
        index = 0;
        rowIndex++;
    }

    ind = 0;
    bool duplicate = false;
    char finalColElements[MAX_STRING][MAX_CHAR];
    int averageAges[MAX_STRING];
    int numOf[MAX_STRING];

    for(int i = 0; i < rowIndex; i++) {
        for(int j = 0; j < ind; j++) {
            if(strcmp(colElements[i], finalColElements[j]) == 0) {
                duplicate = true;
                averageAges[j] += ages[i];
                numOf[j]++;
            }
        }

        if(!duplicate) {
            strcpy(finalColElements[ind], colElements[i]);
            averageAges[ind] += ages[i];
            numOf[ind]++;
            ind++;
        }

        if(duplicate) duplicate = false;
    }

    for(int i = 0; i < ind; i++) averageAges[i] = averageAges[i] / numOf[i];

    for(int i = 0; i < ind; i++) {
        fprintf(output, "%s,%d\n", finalColElements[i], averageAges[i]);
    }

    return 0;
}