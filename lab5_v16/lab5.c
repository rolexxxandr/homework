#include <stdio.h>

#define STRINGS 5
#define ELEMENTS 8

void scan_matrix(int matrix[STRINGS][ELEMENTS])
{
    for (int i = 0; i < STRINGS; i++)
    {
        for (int j = 0; j < ELEMENTS; j++)
        {
            printf("STRING(%d) ELEMENT(%d): ", (i+1), (j+1));
            scanf_s("%d", &matrix[i][j]);
        }
        system("cls");
    }
}

void display_matrix(int matrix[STRINGS][ELEMENTS])
{
    printf("matrix:\n");
    for (int i = 0; i < STRINGS; i++)
    {
        for (int j = 0; j < ELEMENTS; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int calculation(int str[ELEMENTS])
{
    int counter = 1;
    int highest = 0;

    for (int i = 1; i < ELEMENTS; i++)
    {
        if (str[i] == str[i - 1])
            counter++;
        else
        {
            if (counter > highest)
                highest = counter;

            counter = 1;
        }
        if (counter > highest)
            highest = counter;
    }
    return highest;
}

void display_strikes(int total_count[STRINGS])
{
    for (int j = 0; j < STRINGS; j++)
    {
        printf("string N%d strike : %d\n", (j + 1), total_count[j]);
    }
}

void add_strikes(int total_count[STRINGS], int matrix[STRINGS][ELEMENTS])
{
    for (int i = 0; i < STRINGS; i++)
    {
        total_count[i] = calculation(matrix[i]);
    }
}

void display_highest_string(int total_count[STRINGS])
{
    int index = 0;
    for (int k = 1; k < STRINGS; k++)
    {
        if (total_count[k] > total_count[k - 1])
            index = k;
    }
    printf("\nthe highest strike has string N%d: %d\n", (index + 1), total_count[index]);
}

int main()
{
    int matrix[STRINGS][ELEMENTS];
    scan_matrix(matrix);

    display_matrix(matrix);

    calculation(matrix[0]);

    int total_count[STRINGS];

    add_strikes(total_count, matrix);
    display_strikes(total_count);
    display_highest_string(total_count);

}
