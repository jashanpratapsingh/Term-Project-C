#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h> // Include required libraries

#define MAX_LENGTH 1024   // Define the maximum length of each line from CSV


int main(){
    FILE *file, *q6 , *q7, *q8 ,*q9,*q10, *q11;
    
    file = fopen("GlobalTemperatures.csv", "r");
    if (!file){
        printf("Cannot open file!\n");
        return 1;
        // Lets you know that you don't have the csv file in the right place
    }

    printf("Welcome to the Term Project Program!");


 printf("\n Question 1 \n\n");
    /* Question 1, Find the land Temperature 
     * average between 1760 - 2015 */
     
    int count = 0, i =0, n;
    char temp[MAX_LENGTH];
    char *token, *monthlyavg, *year;
    double currentyearlyavg=0,yearaverage[255], dmonthlyavg, centuryavg[MAX_LENGTH], century ;
	// Takes the first line and puts it into temp
	fgets(temp,MAX_LENGTH,file);
	
	do {
		// Skips the header line
		fgets(temp,MAX_LENGTH,file);
		
		// Split the line at the commas
		token = strtok(temp,",");
		monthlyavg = strtok(NULL,",");
		// Split the line at the dashes to get the year
		year = strtok(token,"-"); 
		
		// Convert the year to a int and check its alteast 1960
		if ( atoi(year) >= 1760){
			if (monthlyavg != NULL){
			// Convert the monthly average to a double (float)
			dmonthlyavg=atof(monthlyavg);
			currentyearlyavg += dmonthlyavg;
			count += 1;
		} }
		/* If the count reaches 12 (a year has 12 months)
		 * take the running total and find the average*/
		if (count == 12){
			currentyearlyavg = currentyearlyavg/12;
			yearaverage[i]=currentyearlyavg;
			// Move on to the next spot in the array
			i++;
			// Reset count and yearly average
			count = 0;
			currentyearlyavg=0;
		}
		
	}while (!(feof(file)));
	
	
	fclose(file);
	
	// Display heading
	printf("   Year	 Avg Temp(C*)\n   ----  ----------\n");
	for (i=0; i <=255; i++)
		printf("   %d  %lf\n",i+1760,yearaverage[i]);
		
     printf("\nQuestion 2\n\n");
    /* Calculate the average land temperature value for every century*/
    
    count = 0;
	n=0;
	
	// Display column headings
	printf("Century    AverageTemperature\n");
	/*Loop through each index of the yearaverage array which corresponds to a specific year
	 * keep track of the years using an i index */
    for (i = 1760; i <= 1760+256; i++){
		// If the year is divisible by 100 or it's 2016 calculate the average for the century
		if  (i % 100 ==0 || i  == 2016){
			
			// Divide the running total by amount of years in the century
			century /= count;
			centuryavg[n] = century;
			
			// Prints a table with the century average
			printf("%d-%d   %lf \n",i-count,i-1,centuryavg[n]);

			// Count to keep track of century
			n++;
			/* Reset the numbers of years in the century to 0, reset
			 * the running total for the century to 0*/
			count=0;
			century =0;
		}
		// Running total for every year
		century += yearaverage[i-1760] ;
		/* Count to keep track of the years per century since the centuries 
		 * have irregular number of year */
		count++;

	}
    
	

    printf("\nQuestion 3\n\n");
    double monthlyaverage[12] ;
    char months[][MAX_LENGTH]= { {"January"}, {"February"},{"March"},{"April"},{"May"},{"June"},{"July"},{"August"},{"September"},{"October"},{"November"},{"December"}}  ;
    
    count = 0;
    file = fopen("GlobalTemperatures.csv", "r");
    
    do {
		// First is useless so go to the second
		fgets(temp,MAX_LENGTH,file);
		
		// Split the line at the commas
		token = strtok(temp,",");
		monthlyavg = strtok(NULL,",");
		// Split the line at the dashes to get the year
		year = strtok(token,"-"); 
		// Convert the year to a int and check its alteast 1960
		if ( atoi(year) >= 1900){
			if (monthlyavg != NULL){
					// Add the monthly avg to a running total for each month
					monthlyaverage[count] = monthlyaverage[count] + atof(monthlyavg);
					// Move onto the next month
					count++;
			}
			}
		// If the month counter goes past 11 it resets back to 0, corresponding to january
		if (count == 12){
			count = 0;
		}
	}while (!(feof(file)));
	
	fclose(file);
	
	for (i = 0 ; i < 12 ; i++){
		// Divide each running total by 116, the amount each month occurs between 1900 - 2015
		monthlyaverage[i] /= 116;
	}
    
    // Display column heading
    printf("Month      Avg Temp\n-----      -----\n");
    // Cycle through the monthlyaverage array printing each monthly average
    for (i = 0 ; i < 12 ; i++){
		printf("%-9s % 6.3lf \n",&months[i][0],monthlyaverage[i]);
	}
	
	
    
    
   

    printf("\n\nQuestion 4\n\n");
    
    
    file = fopen("GlobalTemperatures.csv", "r");
    double htemperature = -99, ctemperature = 100;
    int hyear, cyear,hmonth,cmonth;
    
    
    
	do {
		fgets(temp,MAX_LENGTH,file);
		// Split the line at the commas
		token = strtok(temp,",");
		// Get the 2nd comma delimit value which is the monhtly average
		monthlyavg = strtok(NULL,",");
		// Split the line at the dashes to get the year
		year = strtok(token,"-"); 
		// Convert the year to a int and check its alteast 1960
		if ( atoi(year) >= 1760){
			if (monthlyavg != NULL){
				// Set a count to correspond to each month
					count ++;
					/* If the current monthly avg is greater than
					 * the hottest temperature set that temperature
					 * as the new hottest temperaute 
					 * and take note of the  month year in which it occured*/
					if (atof(monthlyavg) > htemperature) {
						htemperature = atof(monthlyavg);
						hyear = atoi(year);
						hmonth = count;
					}
						/* If the current monthly avg is less than
					 * the coldest temperature set that temperature
					 * as the new coldest temperaute 
					 * and take note of the  month year in which it occured*/
					if (atof(monthlyavg) < ctemperature) {
						ctemperature = atof(monthlyavg);
						cyear = atoi(year);
						cmonth = count;
					}
			}
			}
		// Reset the month counter if the month goes past 11(december)a
		if (count == 12){
			count = 0;
		}
		}while (!(feof(file)));
    
    fclose(file);
    
    // Print the results
    printf("Hottest Month: %-9s%d  Temperature: %lf\n",&months[hmonth-1][0],hyear, htemperature);
    printf("Coldest Month: %-9s%d  Temperature: %lf\n",&months[cmonth-1][0],cyear, ctemperature);
    

    printf("\nQuestion 5\n\n");
    
    hyear=0, cyear=0;
    
    htemperature= yearaverage[0]; ctemperature = yearaverage[0];
    
	// Loop through the years from 1760 to 2016
	for (i=0; i <=255; i++){
		// If the current year's average is hotter than the current hottest temperature
		if (yearaverage[i] > htemperature){
			// Update the hottest temperature and year
			htemperature = yearaverage[i];
			hyear = i + 1760;
		}
		// If the current year's average is colder than the current coldest temperature
		if (yearaverage[i] < ctemperature){
			// Update the coldest temperature and year
			ctemperature = yearaverage[i];
			cyear = i + 1760;
		}
    }
    
    // print the results
    printf("Hottest Year: %d Avg Temp: %lf\n",hyear, htemperature);
    printf("Coldest Year: %d Avg Temp: %lf\n",cyear, ctemperature);

    

    printf("\nQuestion 6\n");
    
    // Open a file to place the corresponding data into
    q6 = fopen("GNUplot/q6_data.txt","w");
    
    
    // Create column headers
    fprintf(q6, "Year Yearly_Average_Temperature\n");
    
    // Place yearly averages into data file
    for (i = 0 ; i <= 255 ; i++){
		fprintf(q6,"%d %lf \n",1760+i, yearaverage[i]);	
	}
    
    // Close the file
    fclose(q6);
    

    printf("\nQuestion 7\n");
	
	// Open a file to place the corresponding data into
    q7 = fopen("GNUplot/q7_data.txt","w");
    
    
    // Create column headers
    fprintf(q7, "Year 18th_century_avgtemp 19th_century_avgtemp\n");
    
    // Place yearly averages into data file
    for (i = 0 ; i <= 255 ; i++){
		if ( (i+1760) >= 1800 && (i+1760) <=1899 ){
			fprintf(q7,"%d %lf %lf \n",i-40, yearaverage[i], yearaverage[i+100]);	
		}
	}
    
    // Close the file
    fclose(q7);
	
    printf("\nQuestion 8\n");
    
    double landmaxtempd, landmintempd, landmaxr = 0, landminr = 0, landmaxtempa[MAX_LENGTH], landmintempa[MAX_LENGTH];
    char *landmaxtemp, *landmintemp;
    
    file = fopen("GlobalTemperatures.csv", "r");
	count = 0; n = 0; i= 0;
	//takes the first line and puts it into temp
	fgets(temp,MAX_LENGTH,file);
	
	do {
		// Skips header line
		fgets(temp,MAX_LENGTH,file);
		
		// Split the line at the commas
		token = strtok(temp,",");
		monthlyavg = strtok(NULL,",");
		// Loop through the comma delimited values to find the max land temp
		for (n = 0 ; n < 2 ; n++){
			landmaxtemp = strtok(NULL,",");
		}
		// Loop through the comma delimited values to find the min land temp
		for (n = 0 ; n < 2 ; n++){
			landmintemp = strtok(NULL,",");
		}
		// Split the line at the dashes to get the year
		year = strtok(token,"-"); 

		// Convert the year to a int and check its alteast 1850
		if ( atoi(year) >= 1850){
			if (monthlyavg != NULL){
		
		
			// Convert the landmin & max temps from a pointer to a double
			landmaxtempd=atof(landmaxtemp);
			landmintempd=atof(landmintemp);
			
			// Add the landmin and maxtemps to a running total
			landmaxr += landmaxtempd;
			landminr += landmintempd;
			count += 1;
			}
		} 
		/* If the count reaches 12 (a year has 12 months)
		 * take the running total and find the average*/
		if (count == 12){
			// Divide the running totals by 12, to find the yearly averages
			landmaxr = landmaxr/12;
			landminr=landminr/12;
			// Add the yearly averages to an array
			landmaxtempa[i]=landmaxr;
			landmintempa[i]=landminr;
			// Move to next spot in array
			i++;
			// Reset count and yearly average
			count = 0;
			landmaxr=0;
			landminr=0;
			
		}
		
	}while (!(feof(file)));
	
	
	// Open a file to place the corresponding data into
    q8 = fopen("GNUplot/q8_data.txt","w");
    
    
    // Create column headers
    fprintf(q8, "Year Land_Average_Temp LandMaxTemp LandMintemp\n");
    
    // Place yearly averages into data file
    for (i = 0 ; i <= 255 ; i++){
		if ( (i+1760) >= 1850  ){
			fprintf(q8,"%d %lf %lf %lf \n",i+1760, yearaverage[i], landmaxtempa[i-90],landmintempa[i-90]);	
		}
	}

	// Close the file
	fclose(file);

    printf("\nQuestion 9\n");
	
	// Open the file "q9_data.txt" in write mode
	q9 = fopen("GNUplot/q9_data.txt","w");

	// Write the header line to the file
	fprintf(q9,"# Century AverageLandTemp AverageMaxLandTemp AverageMinLandTemp\n");
	count = 0; century = 0; int z= 0;
	
	// Loop through the years from 1850 to 2016
	for (i = 1850; i <= 1850+196; i++){
		// If the current year is a century year or the year 2016
		if  (i % 100 ==0 || i  == 2016){
			
			// Calculate the average temperature, max temperature, and min temperature for the century
			century /= count;
			landmaxr /= count;
			landminr /=count;
			
			// Write the century, year range, and average temperatures to the file
			fprintf(q9,"%d %d-%d   %lf %lf %lf \n",z,i-count,i-1,century,landmaxr,landminr);

			// Increment counters, and reset variables
			z++;
			n++;
			count=0;
			century =0;
			landmaxr=0;
			landminr=0;
		}
		
		 // Add the average temperature, max temperature, and min temperature for the current year to the totals for the century
		century += yearaverage[i-1760] ;
		landmaxr += landmaxtempa[i-1850];
		landminr += landmintempa[i-1850];
		count++;

	}

	// Close the file
	fclose(q9); 

	// Declare a char pointer monthlyunc and a double array monthlyunccount with 12 elements
	char* monthlyunc;
	double monthlyunccount[12]; 
	
    printf("\nQuestion 10\n");

	// Open the file "q10_data.txt" in write mode and "GlobalTemperatures.csv" in read mode
    q10=fopen("GNUplot/q10_data.txt","w");file = fopen("GlobalTemperatures.csv","r");
    
	// Initialize count to 0
	count = 0;
    
	// Initialize the monthlyaverage array to 0
    for (i=0;i<12;i++){
		monthlyaverage[i]=0;
	}
    
    do {
		fgets(temp,MAX_LENGTH,file);
		// Split the line at the commas and store the values
		token = strtok(temp,",");
		monthlyavg = strtok(NULL,",");
		// Loop through the comma delimeted values to find the monthly uncertainty
		for (n= 0; n <1 ; n++){
			monthlyunc = strtok(NULL,",");
		}

		// Split the token at the dashes to get the year and store it in year
		year = strtok(token,"-");

		/* If the year is 2000 or later and monthlyavg and monthlyunc are not NULL,
		add the monthly average and uncertainty to the totals for the current month */
		if ( atoi(year) >= 2000){
			if (monthlyavg != NULL && monthlyunc != NULL){
					monthlyaverage[count] = monthlyaverage[count] + atof(monthlyavg);
					monthlyunccount[count] = monthlyunccount[count] +atof(monthlyunc);
					count++;
			}
			}
		
		// If count reaches 12, a year's worth of data has been processed, so reset count for the next year
		if (count == 12){
			count = 0;
		}
	
	// Continue the loop until the end of the file is reached
	}while (!(feof(file)));
    
    /* Divide the running totals in each index of the array to calulate the 
     * average value for the month*/
	for (i = 0 ; i < 12 ; i++){
		monthlyaverage[i] /= 16;
		monthlyunccount[i] /= 16;
	}
    
	// Add the average monthly temperature and uncertainty for the 16 years from 2000 to 2015 to the data file
    for (i = 0 ; i < 12 ; i++){
		fprintf(q10,"%-9s % 6.3lf % 6.3lf \n",&months[i][0],monthlyaverage[i],monthlyunccount[i]);
	}
	
	// Close the files
	fclose(q10);fclose(file);

    printf("\nQuestion 11\n");
    
	// Declare variables
    char* oceantempavg;
    double oceantempavgrun, oceantempavga[MAX_LENGTH];
    
	// Open the file "GlobalTemperatures.csv" in read mode and "q11_data.txt" in write mode
    file = fopen("GlobalTemperatures.csv", "r");
    q11=fopen("GNUplot/q11_data.txt","w");

	// Write the header line to the file
	fprintf(q11, "Date  Landtemp LandAndOceanTemp\n");
	
	// Initialize count and i to 0
	count = 0; i= 0;
	
    do {
		// Ignore the header line
		fgets(temp,MAX_LENGTH,file);
		
		// Split the line at the commas and store the tokens
		token = strtok(temp,",");
		monthlyavg =  strtok(NULL,",") ;
		/* Loop through the comma delimited values to get the values in 
		 *the average ocean & land temp colum */
		for (n=0; n <= 5 ; n++){
			oceantempavg = strtok(NULL,",")  ;
		}
		
		// Split the line at the dashes to get the year and store it in year
		year = strtok(temp,"-"); 
		
		// Convert the year to a int and check its at least 1850
		if ( atoi(year ) >= 1850){
			// If monthlyavg and oceantempavg are not NULL, add the ocean temperature to the running total
			if (monthlyavg != NULL && oceantempavg != NULL){
					oceantempavgrun += atof(oceantempavg);
					count++;
			}
			}

		// If count reaches 12, a year's worth of data has been processed
		if (count == 12){
			// Calculate the average ocean temperature for the year
			oceantempavgrun /= 12;
			// Store the average ocean temperature in the array
			oceantempavga[i]=oceantempavgrun;
			// clear the running total
			oceantempavgrun = 0;
			// Write the year, land temperature, and ocean temperature to the file
			fprintf(q11,"%d %lf %lf\n",atoi(year),yearaverage[i+90],oceantempavga[i]);
			// Move to the next spot in the array
			i++;
			count = 0;
		}
		
	// Continue the loop until the end of the file is reached
	}while (!(feof(file)));
	
	// Close the files
	fclose(file); fclose(q11);
	

	

    printf("Thank you, goodbye!");

    return 0;
}