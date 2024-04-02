#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    FILE *fptr;

    //Opening the file in the read mode
    fptr= fopen("GlobalTemperatures.csv", "r");

    if (fptr==NULL) {
        printf("Error Opening the file/n");
    }
    //Stroring the content of the file
    char myString[100];

    int isFirstLine = 1;

    // Read the file line by line
    while (fgets(line, sizeof(line), fptr)) {
    // Skip the header (first line)
        if (isFirstLine) {
            isFirstLine = 0;
            continue;
        }
        


    return 0;
}