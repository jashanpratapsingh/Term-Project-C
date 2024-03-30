#include <stdio.h>
#include <stdlib.h>

#define NUM_YEARS 256

int main() {

    // Question 1: Reading and calculating yearly averages
    FILE *file = fopen("GlobalTempaeratures.csv", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    double yearly_averages[NUM_YEARS] = {0};
    int yearly_counts[NUM_YEARS] = {0};

    // Skip header
    fscanf(file, "%*[^\n]");
    fgetc(file);

    int year;
    double temperature;

    // Read data and calculate yearly averages
    while (fscanf(file, "%d,%*f,%*f,%*f,%*f,%*f,%*f,%lf", &year, &temperature) == 2) {
        if (year >= 1760 && year <= 2015) {
            int index = year - 1760;
            yearly_averages[index] += temperature;
            yearly_counts[index]++;
        }
    }

    fclose(file);

    // Output yearly averages
    printf("Year\tAverage Temperature\n");
    for (int i = 0; i < NUM_YEARS; i++) {
        if (yearly_counts[i] > 0) {
            double avg_temp = yearly_averages[i] / yearly_counts[i];
            printf("%d\t%.2f\n", i + 1760, avg_temp);
        }
    }

    // Question 2: Calculating average land temperature
    file = fopen("GlobalTemperatures.csv", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    char line[100];
    double total_temperature = 0;
    int count = 0;

    // Skip the header line
    fgets(line, sizeof(line), file);

    // Read each line and calculate the total temperature
    while (fgets(line, sizeof(line), file)) {
        sscanf(line, "%*[^,],%lf", &temperature);
        total_temperature += temperature;
        count++;
    }

    // Calculate and print the average temperature
    if (count > 0) {
        double average_temperature = total_temperature / count;
        printf("Average Land Temperature: %.2f\n", average_temperature);
    } else {
        printf("No data found.\n");
    }

    fclose(file);

    return 0;
}
