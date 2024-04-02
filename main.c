#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_LINE_LENGTH 1024


int main() {

    //Common Parts of the Program
    char line[MAX_LINE_LENGTH];
    FILE *file, *q6, *q7, *q8, *q9, *q11;
    int count=0, i=0,n;
    char *token, *year, *temp;
    double yearlyavg=0, allyearlyavg[256], dtemp, centavg[MAX_LINE_LENGTH], cent;
    file = fopen("GlobalTemperatures.csv", "r");
    if (!file) {
        printf("There was a error opening this file.\n");
        return 1;
    }

    printf("This is where the term project starts!\n");

    // Question 1: Reading and calculating yearly average
    printf("Solution 1\n\n");
    // Here the goal is to find the average land temperature of each year between 1760-2015


    do {
        //skipping the header line here
        fgets(line, MAX_LINE_LENGTH, file);

        //Splitting the line at the delimiter which is a comma
        token = strtok(line, ",");
        temp = strtok(NULL, ",");
        year = strtok(token,"-");

        if (atoi(year) >= 1760){
            if (temp != NULL){
                dtemp=atof(temp);
                printf("%lf", dtemp);
                yearlyavg += dtemp;
                count += 1;
            }
        }

        if (count == 12){
            yearlyavg = yearlyavg/12;
            allyearlyavg[i]=yearlyavg;
            i++;
            count=0;
            yearlyavg=0;
            
        }


    }while(!(feof(file)));

    fclose(file);

    printf(" The yearly average here is(C*)\n   ----    -----------\n");
    for (i=0;i <= 255;i++)
    printf("   %d  %lf\n", i+1760, allyearlyavg[i]);


    // Question 2: Calculating average land temperature
    printf("\nQuestion 2\n\n");

    // Here we had already created a yearly average array in the beginning which enabled us
    // to take the years out
    //Now we will use tghat array here and loop through it
    count = 0;
    n=0;
    // Here we will display the heading
    printf("The Century       The Average temperature of the Ceentury\n");

    for (i = 1760; i <= 1760+256; i++){
        if (i%100 ==0 || i ==2016){
            cent /= count;
            centavg[n] = cent;

            printf("%d-%d     %lf \n", i-count,i-1,centavg[n]);
            n++;

            count=0;
            cent=0;
        }

        cent += allyearlyavg[i-1760];
        count++;
    }

    //Question 3: Average temperature of each month for all the months combined between 1990 2015

    printf(" Question 3\n");
    double temp_new[12];
    char mon[][MAX_LINE_LENGTH] = {{"1st Month"}, {"2nd Month"}, {"3th Month"}, {"4th Month"}, {"5th Month"}, {"6th Month"},{"7th Month"},{"8th Month"},{"9th Month"},{"10th Month"},{"11th Month"},{"12th Month"}};

    count = 0 ;
    file = fopen("GlobalTemperatures.csv", "r");
    do {
    fgets(line, MAX_LINE_LENGTH, file);

    token = strtok(line,",");
    temp_new = strtok(NULL, ",");
    year = strtok(token,"-");

    if (atoi(year) >= 1900) {
        if(temp != NULL) {
            temp_new[count] = temp_new[count] + atof(temp);
            count++;
        }
    }
    if (count == 12) {
        count = 0;
    }
}while (!(feof(file)));

    fclose(file);

    for (i=0 ; i < 12 ; i++) {
        temp_new[i] /= 116;
    }

    printf("The Month       Avg Temp\n------    -------\n");
    for (i = 0 ; i < 12 ; i++) {
        printf("%-9s % 6.3lf \n", &mon[i][0], temp_new[i]);
    }

    return 0;
}
