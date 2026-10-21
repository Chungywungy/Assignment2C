/*
 * COMP 2510 - Fall 2026
 * Homework Assignment 2
 *
 * Complete each function below.
 * Do not change the required function names or parameter lists.
 *
 * Student Name: Fawaz Shariff
 * Student Number: A01443086
 */

#include <stdio.h>
#include <stddef.h>

/* Task 1: Subtract Corresponding Array Elements */
void subtractArrays(const double first[],
                    const double second[],
                    double result[],
                    size_t size)
{
    for (size_t i = 0; i < size; i++) {
        result[i] = first[i] - second[i];
    }
}


/* Task 2: Find the Index of the Smallest Value */
int myMin(const double values[], size_t size)
{
    int min = 1;
    for (size_t i = 0; i <= size; i++) {
        if (values[i] < values[min]) {
            min = i;
            return min;
        }
    }
    return min;
}


/* Task 3: Reverse-Copy an Array Using Subscripts */
void reverseCopyArray(const double source[], double target[], size_t size)
{
    /* TODO: Use array-subscript notation. */
}


/* Task 3: Reverse-Copy an Array Using Pointers */
void reverseCopyPointer(const double *source, double *target, size_t size)
{
    /* TODO: Use pointer notation and pointer movement.
       Do NOT use square-bracket array notation in this function. */
}


/* Task 4(a): Calculate a Week's Average */
double calculateWeekAverage(const double week[], size_t size)
{
    /* TODO: */
    return 0.0;
}


/* Task 4(b): Calculate the Overall Average */
double calculateOverallAverage(const double temperatures[][7], size_t rows)
{
    /* TODO: */
    return 0.0;
}


/* Task 4(c): Find the Largest Temperature */
double findLargestTemperature(const double temperatures[][7], size_t rows)
{
    /* TODO: */
    return 0.0;
}


/* Task 4(e): Count Temperatures Above the Overall Average */
int countAboveAverage(const double temperatures[][7],
                      size_t rows,
                      double overallAverage)
{
    /* TODO: Count values STRICTLY greater than overallAverage. */
    return 0;
}


#ifdef TEST_ASSIGNMENT

int main(void)
{
    /* Task 1: Subtract Corresponding Array Elements */
    printf("Task 1 - subtractArrays\n");
    double first[] = {25.0, 40.0, 55.0, 70.0};
    double second[] = {5.0, 10.0, 15.0, 20.0};
    double result[4] = {0};
    size_t count = sizeof(first) / sizeof(first[0]);

    subtractArrays(first, second, result, count);
    printf("Expected: 20.0 30.0 40.0 50.0\n");
    printf("Your output: ");
    for (size_t i = 0; i < count; i++) {
        printf("%.1f ", result[i]);
    }
    printf("\n\n");


    /* Task 2: Find the Index of the Smallest Value */
    printf("Task 2 - myMin\n");
    double values[] = {7.4, 3.2, 9.8, 1.5, 6.1};
    printf("myMin(values, 5) = %d (expected 3)\n",
           myMin(values, 5));

    double repeated[] = {2.0, -4.0, 5.0, -4.0};
    printf("myMin(repeated, 4) = %d (expected 1)\n\n",
           myMin(repeated, 4));


    /* Task 3: Reverse-Copy an Array
       The original array and both target arrays are declared in main(). */
    printf("Task 3 - Reverse Copy\n");
    double original[] = {2.5, 4.0, 6.5, 8.0, 10.5};
    double copiedWithSubscripts[5] = {0};
    double copiedWithPointers[5] = {0};
    size_t length = sizeof(original) / sizeof(original[0]);

    reverseCopyArray(original, copiedWithSubscripts, length);
    reverseCopyPointer(original, copiedWithPointers, length);

    printf("Expected for both: 10.5 8.0 6.5 4.0 2.5\n");
    printf("reverseCopyArray:   ");
    for (size_t i = 0; i < length; i++) {
        printf("%.1f ", copiedWithSubscripts[i]);
    }
    printf("\nreverseCopyPointer: ");
    for (size_t i = 0; i < length; i++) {
        printf("%.1f ", copiedWithPointers[i]);
    }
    printf("\n\n");


    /* Task 4: Analyze Weekly Temperature Data */
    printf("Task 4 - Weekly Temperatures\n");
    double temperatures[4][7];

    /* Task 4: Read 7 temperatures for each of 4 weeks. */
    for (size_t week = 0; week < 4; week++) {
        printf("Enter 7 temperatures for week %zu:\n", week + 1);
        for (size_t day = 0; day < 7; day++) {
            if (scanf("%lf", &temperatures[week][day]) != 1) {
                printf("Invalid input.\n");
                return 1;
            }
        }
    }

    /* Task 4(a): Calculate each week's average. */
    for (size_t week = 0; week < 4; week++) {
        printf("Week %zu average: %.2f\n",
               week + 1, calculateWeekAverage(temperatures[week], 7));
    }

    /* Task 4(b, c, e): Analyze all 28 temperatures. */
    const double (*allWeeks)[7] = (const double (*)[7])temperatures;
    double overallAverage = calculateOverallAverage(allWeeks, 4);
    printf("Overall average: %.2f\n", overallAverage);
    printf("Largest temperature: %.2f\n",
           findLargestTemperature(allWeeks, 4));
    printf("Count above overall average: %d\n",
           countAboveAverage(allWeeks, 4, overallAverage));

    return 0;
}

#endif