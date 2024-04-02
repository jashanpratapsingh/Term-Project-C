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

    // Question 2: Calculating average land temperature of 19th, 20th, 21st Century
    //One Average per Century.
            file = fopen("GlobalTemperatures.csv", "r");
            if (file == NULL) {
                printf("Error opening file.\n");
                return 1;
            }
            double total_temperature = 0;
            int count = 0;
            fgets(line, sizeof(line), file);
            while(fgets(line, sizeof(line), in)!= NULL){
		        sscanf(line, "%*[^,],%lf", &temperature);
                sscanf(line, "%d", &year);
		        if (year >= 1801 && year <= 1900) { // 19th century
                    int index = year - 1801;
                    yearly_averages_19th_century[index] += temperature;
                    yearly_counts_19th_century[index]++;
        } else if (year >= 1901 && year <= 2000) { // 20th century
            int index = year - 1901;
            yearly_averages_20th_century[index] += temperature;
            yearly_counts_20th_century[index]++;
        } else if (year >= 
    }

    fprintf(output_file, "Year\tAverage Temperature (19th century)\tAverage Temperature (20th century)\n");
    for (int i = 0; i < NUM_YEARS_PER_CENTURY; i++) {
        if (yearly_counts_19th_century[i] > 0 && yearly_counts_20th_century[i] > 0) {
            double avg_temp_19th_century = yearly_averages_19th_century[i] / yearly_counts_19th_century[i];
            double avg_temp_20th_century = yearly_averages_20th_century[i] / yearly_counts_20th_century[i];
            fprintf(output_file, "%d\t%.2f\t%.2f\n", i + 1801, avg_temp_19th_century, avg_temp_20th_century);
        }
    }

    fclose(input_file);
    fclose(output_file);

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

                


    return 0;
}
