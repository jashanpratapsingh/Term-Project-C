#include <stdio.h>
#include <stdlib.h>

#define NUM_YEARS 256
#define NUM_MONTHS 12

int main() {

    // Question 1: Reading and calculating yearly averages
                FILE *file = fopen("GlobalTemperatures.csv", "r");
                if (file == NULL) {
                    printf("Error opening file.\n");
                    return 1;
                }

                double yearly_averages[NUM_YEARS] = {0};
                int yearly_counts[NUM_YEARS] = {0};
                fscanf(file, "%*[^\n]");
                fgetc(file);

                int year;
                double temperature;
                char line[100];
                while (fgets(line, sizeof(line), file) != NULL) {
                    sscanf(line, "%*[^,],%lf", &temperature);
                    sscanf(line, "%d", &year);
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
            double total_temperature = 0;
            int count = 0;
            fgets(line, sizeof(line), file);
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

    //Question 3: Average temperature of each month for all the months combined between 1990 2015
                double monthly_averages[NUM_MONTHS] = {0};
                int monthly_counts[NUM_MONTHS] = {0};

                file = fopen("GlobalTemperatures.csv", "r");
                if (file == NULL) {
                    printf("Error opening file.\n");
                    return 1;
                }

                fgets(line, sizeof(line), file);
                char month[3];

                while (fscanf(file, "%d-%2[^-]-%*d,%2lf", &year, month, &temperature) == 3) {
                    if (year >= 1900 && year <= 2015) {
                        int index;
                        if (year == 1900)
                            index = atoi(month) - 1;
                        else
                            index = (year - 1900) * 12 + atoi(month) - 1;
                        monthly_averages[index] += temperature;
                        monthly_counts[index]++;
                    }
                }

                fclose(file);

                // Calculating the montly temperatures
                printf("Month\tAverage Temperature\n");
                for (int i = 0; i < NUM_MONTHS; i++) {
                    if (monthly_counts[i] > 0) {
                        double avg_temp = monthly_averages[i] / monthly_counts[i];
                        printf("%d\t%.2f\n", i + 1, avg_temp);
                    }
                }


    return 0;
}
