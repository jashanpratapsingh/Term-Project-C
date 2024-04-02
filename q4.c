#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MaxLineLength 1024
#define DELIMITER ","

int main() {
    FILE *file;
    char line[MaxLineLength];
    float HighestTemperature = -100.0; // Initializing to very low temperature
    float LowestTemperature = 100.0;   // Initializing to very high temperature
    char HottestMonth[20];
    char ColdestMonth[20];

    // Open the CSV file
    file = fopen("GlobalTemperatures.csv", "r");
    if (file == NULL) {
        printf("Error: Unable to open file.\n");
        return 1;
    }
    
    // Read and parse data
    while (fgets(line, sizeof(line), file)) {
        // Tokenize the line using strtok()
        char *token = strtok(line, DELIMITER);
        char *year = token; // First token is the year
        token = strtok(NULL, DELIMITER); // Move to the next token
        
        // Parse land average temperature
        float temp = atof(token); // Convert string to float
        
        // Update hottest and coldest temperatures
        if (temp > HighestTemperature) {
            HighestTemperature = temp;
            strcpy(HottestMonth, year);
        }
        if (temp < LowestTemperature) {
            LowestTemperature = temp;
            strcpy(ColdestMonth, year);
        }
    }
    
    // Close the file
    fclose(file);
    
    // Print results
    printf("Hottest month recorded: %s\n", HottestMonth);
    printf("Coldest month recorded: %s\n", ColdestMonth);
    
    return 0;
}