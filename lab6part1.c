#include <stdio.h>
/*Adira Mongar
ID 3108424
Lab 6
this program takes an imput file with 12 months of sales reports and geterates the Monthly Sales Report,
Sales Summary Report, Six-Month Moving Average Report and Sales Report Highest to Lowest*/

void monthlySalesReport(double sales[],char months[]);
void salesSummary(double sales[],char months[]);
void sixMonthMovingAverage(double sales[],char months[]);
void salesHighestToLowest(double sales[],char months[]);

void main() {
    FILE *file;
    double sales[12];
    int i = 0;
	char filename[30];
	char *months[12] = {
    "January", "February", "March", "April", "May", "June", 
    "July", "August", "September", "October", "November", "December"};
	// get name of file
	scanf("%s", filename);
    // open and read input
	    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Could not open file.\n");
	exit()
    }

    // read sale numbers and store them in sales array for further use
    while (i < 12 && fscanf(file, "%f", &numbers[i]) == 1) {
        i++;
    }

    // Close
    fclose(file);
	
	 // this prints the Monthly Sales Report
	monthlySalesReport(sales[],months[])
	salesSummary(double sales[],char months[]);
	sixMonthMovingAverage(double sales[],char months[]);
	salesHighestToLowest(double sales[],char months[]);
}

void monthlySalesReport(double sales[],char months[]){
	printf("Monthly Sales Report for 2024\n\n");
    printf("Month        Sales\n");
    for (int i = 0; i < 12; i++) {
        printf("%-12s $%.2f\n", months[i], sales[i]);
    }
}
void salesSummary(double sales[],char months[]){
    double min = sales[0], max = sales[0], sum = 0.0;
    int minMonth = months[0], maxMonth = months[0];

    for (int i = 0; i < 12; i++) {
        if (sales[i] < min) {
            min = sales[i];
            minMonth = months[i];
        }
        if (sales[i] > max) {
            max = sales[i];
            maxMonth = months[i];
        }
        sum += sales[i];
	}
	double average = sum / 12;

    printf("\nSales summary report:\n");
    printf("Minimum sales: $%.2f (%s)\n", min, minMonth);
    printf("Maximum sales: $%.2f (%s)\n", max, maxMonth);
    printf("Average sales: $%.2f\n", average);
}
void sixMonthMovingAverage(double sales[],char months[]) {
    printf("\nSix-Month Moving Average Report:\n");

    for (int i = 0; i <= 6; i++) {
        double sum = 0.0;
        for (int j = i; j < i + 6; j++) {
            sum += sales[j];
        }
        printf("%s-%s: $%.2f\n", months[i] , months[i +5], sum / 6);
    }
}
void printSalesHighestToLowest(double sales[],char months[]) {
    printf("\nSales Report (Highest to Lowest):\n");

    double sortedSales[12];
    for (int i = 0; i < 12; i++) {
        sortedSales[i] = sales[i];
    }

    // Sort sales from highest to lowest
    for (int i = 0; i < 11; i++) {
        for (int j = i + 1; j < 12; j++) {
            if (sortedSales[i] < sortedSales[j]) {
                double temp = sortedSales[i];
                sortedSales[i] = sortedSales[j];
                sortedSales[j] = temp;
            }
        }
    }

    // Print sorted sales
    printf("Month        Sales\n");
    for (int i = 0; i < 12; i++) {
        printf("%-12s $%.2f\n", months[i], sales[i]);
    }
}