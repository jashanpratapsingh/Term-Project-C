#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_YEARS_PER_CENTURY 100
#define START_YEAR 1760
#define END_YEAR 2016
#define NUM_CENTURIES ((END_YEAR - START_YEAR) / NUM_YEARS_PER_CENTURY)

int main() {
    // Define variables
    double yearaverage[END_YEAR - START_YEAR] = {0}; // Array to store yearly average temperatures
    double centuryavg[NUM_CENTURIES] = {0}; // Array to store century average temperatures

    // Read data and calculate yearly averages (Question 1)
    FILE *file = fopen("GlobalTemperatures.csv", "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    char line[1024];
    fgets(line, sizeof(line), file); // Skip header line

    int yearIndex = 0;
    while (fgets(line, sizeof(line), file)) {
        char *token = strtok(line, ",");
        strtok(NULL, ","); // Skip LandAverageTemperature

        int year = atoi(strtok(token, "-"));
        if (year >= START_YEAR && year < END_YEAR) {
            double temperature = atof(strtok(NULL, ","));
            yearaverage[yearIndex++] = temperature;
        }
    }
    fclose(file);

    // Calculate century averages (Question 2)
    printf("Century    AverageTemperature\n");
    for (int i = 0; i < NUM_CENTURIES; i++) {
        double centurySum = 0;

        // Calculate sum of temperatures for the current century
        for (int j = 0; j < NUM_YEARS_PER_CENTURY; j++) {
            int yearIndex = i * NUM_YEARS_PER_CENTURY + j;
            if (yearIndex < END_YEAR - START_YEAR) {
                centurySum += yearaverage[yearIndex];
            }
        }

        // Calculate and print average temperature for the current century
        double centuryAverage = centurySum / NUM_YEARS_PER_CENTURY;
        printf("%d-%d   %.2lf\n", START_YEAR + i * NUM_YEARS_PER_CENTURY,
               START_YEAR + (i + 1) * NUM_YEARS_PER_CENTURY - 1, centuryAverage);
    }

    return 0;
}
