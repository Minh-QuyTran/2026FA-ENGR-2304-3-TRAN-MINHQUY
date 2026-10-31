/*2026FA-ENGR-2304-3-TRAN-MINHQUY-P06*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_ROWS 2000
#define NUM_L 6

typedef struct
{
    int year;
    int month;
    int day;
    double values[NUM_L];
} Record;

int loadData(const char* filename, Record data[])
{
    FILE* file;
    char line[300];
    int count = 0;

    file = fopen(filename, "r");

    if (file == NULL)
    {
        printf("Error: Could not open file.\n");
        return 0;
    }

    if (fgets(line, sizeof(line), file) == NULL)
    {
        fclose(file);
        return 0;
    }

    while (fgets(line, sizeof(line), file) != NULL
        && count < MAX_ROWS)
    {
        if (sscanf(line,
            "%d,%d,%d,%lf,%lf,%lf,%lf,%lf,%lf",
            &data[count].year,
            &data[count].month,
            &data[count].day,
            &data[count].values[0],
            &data[count].values[1],
            &data[count].values[2],
            &data[count].values[3],
            &data[count].values[4],
            &data[count].values[5]) == 9)
        {
            count++;
        }
    }

    fclose(file);
    return count;
}

double Cal_Mean(double values[], int count)
{
    double sum = 0.0;
    int i;

    if (count <= 0)
        return 0.0;

    for (i = 0; i < count; i++)
    {
        sum += values[i];
    }

    return sum / count;
}

double Cal_StdDeviation(double values[], int count)
{
    double mean;
    double sum = 0.0;
    int i;

    if (count <= 0)
        return 0.0;

    mean = Cal_Mean(values, count);

    for (i = 0; i < count; i++)
    {
        sum += (values[i] - mean) * (values[i] - mean);
    }

    return sqrt(sum / count);
}

double findMinimum(double values[], int count)
{
    int i;
    double min;

    if (count <= 0)
        return 0.0;

    min = values[0];

    for (i = 1; i < count; i++)
    {
        if (values[i] < min)
        {
            min = values[i];
        }
    }

    return min;
}

double findMaximum(double values[], int count)
{
    int i;
    double max;

    if (count <= 0)
        return 0.0;

    max = values[0];

    for (i = 1; i < count; i++)
    {
        if (values[i] > max)
        {
            max = values[i];
        }
    }

    return max;
}

void showReport(Record data[], int count)
{
    double values[MAX_ROWS];
    int column;
    int row;

    printf("\n*** DATA ANALYSIS REPORT ***\n");
    printf("Number of records: %d\n\n", count);

    printf("%-8s %-12s %-12s %-12s %-12s\n",
        "Data", "Mean", "Std Dev", "Minimum", "Maximum");

    printf("--------------------------------------------------------------\n");

    for (column = 0; column < NUM_L; column++)
    {
        for (row = 0; row < count; row++)
        {
            values[row] = data[row].values[column];
        }

        printf("L%-7d %-12.2f %-12.2f %-12.2f %-12.2f\n",
            column + 1,
            Cal_Mean(values, count),
            Cal_StdDeviation(values, count),
            findMinimum(values, count),
            findMaximum(values, count));
    }
}

void searchData(Record data[], int count)
{
    int year;
    int found = 0;
    int i;

    printf("\nEnter year to search: ");

    if (scanf("%d", &year) != 1)
    {
        printf("Invalid year input.\n");
        while (getchar() != '\n');
        return;
    }

    printf("\nSearch Results:\n");
    printf("-----------------------------------------------\n");

    for (i = 0; i < count; i++)
    {
        if (data[i].year == year)
        {
            printf("%04d-%02d-%02d ",
                data[i].year,
                data[i].month,
                data[i].day);

            printf("L1=%g L2=%g L3=%g L4=%g L5=%g L6=%g\n",
                data[i].values[0],
                data[i].values[1],
                data[i].values[2],
                data[i].values[3],
                data[i].values[4],
                data[i].values[5]);

            found++;
        }
    }

    if (found == 0)
    {
        printf("No records found!\n");
    }
    else
    {
        printf("\n%d records found.\n", found);
    }
}

void displayMenu(void)
{
    printf("\n*** PROCESS DATA ANALYSIS ***\n");
    printf("1. Display data analysis report\n");
    printf("2. Search data by year\n");
    printf("3. Exit\n");
    printf("Enter your choice: ");
}

int main(void)
{
    Record data[MAX_ROWS];
    int count;
    int choice;

    count = loadData(
        "ENGR 2304 - Information Session P07 - Process Data Analysis.csv",
        data
    );

    if (count == 0)
    {
        printf("No data was loaded.\n");
        return 1;
    }

    printf("Successfully loaded %d records.\n", count);

    while (1)
    {
        displayMenu();

        if (scanf("%d", &choice) != 1)
        {
            printf("Invalid choice. Please enter 1, 2, or 3.\n");

            while (getchar() != '\n');

            continue;
        }

        if (choice == 1)
        {
            showReport(data, count);
        }
        else if (choice == 2)
        {
            searchData(data, count);
        }
        else if (choice == 3)
        {
            printf("\nProgram exited.\n");
            break;
        }
        else
        {
            printf("Invalid choice. Please enter 1, 2, or 3.\n");
        }
    }

    return 0;
}