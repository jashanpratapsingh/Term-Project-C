#include <stdio.h>
#include <stdlib.h>

int main(void) {
    FILE *fptr;

    //Opening the file in the read mode
    fptr= fopen("GlobalTemperatures.csv", "r");

    if (fptr==NULL) {
        printf("Error Opening the file/n");
    }
    //Stroring the content of the file
    char myString[100];

    return 0;
}