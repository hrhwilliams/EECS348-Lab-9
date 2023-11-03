#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MONTHS 12

const char *months[] = {
    "January",
    "February",
    "March",
    "April",
    "May",
    "June",
    "July",
    "August",
    "September",
    "October",
    "November",
    "December"
};

/*
 * Reads the sales numbers from a text file into the array `sales`
 */
int read_sales_input(const char *filepath, double *sales) {
    FILE *input = fopen(filepath, "r");
    if (input == NULL) {
        return -1;
    }

    char buf[128];
    for (int i = 0; i < MONTHS; i++) {
        fgets(buf, sizeof buf, input);
        sales[i] = atof(buf);
    }

    fclose(input);
    return 1;
}

/*
 * Prints the sales by month
 */
void print_sales(double *sales) {
    printf("Month     Sales\n");
    for (int i = 0; i < MONTHS; i++) {
        printf("%-10s$%.2lf\n", months[i], sales[i]);
    }
}

/*
 * Prints the maximum, minimum, and average sales of the 12-month period
 */
void sales_summary(double *sales) {
    double min = sales[0], max = 0, avg = 0;
    for (int i = 0; i < MONTHS; i++) {
        if (sales[i] > max) {
            max = sales[i];
        }

        if (sales[i] < min) {
            min = sales[i];
        }

        avg += sales[i];
    }
    avg /= MONTHS;

    printf("Sales summary:\n");
    printf("Minimum sales:  $%.2lf\n", min);
    printf("Maximum sales:  $%.2lf\n", max);
    printf("Average sales:  $%.2lf\n", avg);
}

/*
 * Prints a moving average of the sales, where the size of the
 * moving average is specified by `window`
 */
void moving_average_report(double *sales, int window) {
    double avg = 0;

    printf("%d-Month Moving Average Report:\n", window);
    for (int i = 0; i < MONTHS; i++) {
        avg += sales[i];
        if (i >= window - 1) {
            avg -= sales[i - window];
            printf("%-10s - %-10s $%.2lf\n", months[i - window + 1], months[i], avg / window);
        }
    }
}

/*
 * Sorts `sales`, storing the permutations in `month_indices` so the months
 * are printed in the sorted order with the sales
 */
void insertion_sort(double *sales, int *month_indices) {
    for (int i = 1; i < MONTHS; i++) {
        double x = sales[i];
        int j = i - 1;

        while (j >= 0 && sales[j] < x) {
            sales[j+1] = sales[j];
            month_indices[j+1] = month_indices[j];
            j--;
        }

        sales[j+1] = x;
        month_indices[j+1] = i;
    }
}

/*
 * Returns a sales report sorted from most to least sales per month
 *
 * Copies sales as to not mutate the original array
 */
void sorted_sales_report(double *sales) {
    double sorted_sales[MONTHS];
    int sorted_months[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11 };
    memcpy(sorted_sales, sales, MONTHS * sizeof *sales);
    insertion_sort(sorted_sales, sorted_months);

    printf("Month     Sales\n");
    for (int i = 0; i < MONTHS; i++) {
        printf("%-10s$%.2lf\n", months[sorted_months[i]], sorted_sales[i]);
    }
}

int main() {
    double sales[MONTHS];

    if (read_sales_input("input.txt", sales) == -1) {
        printf("Error reading input.txt\n");
        return -1;
    }

    print_sales(sales);
    printf("\n");
    sales_summary(sales);
    printf("\n");
    moving_average_report(sales, 6);
    printf("\n");
    sorted_sales_report(sales);
}
