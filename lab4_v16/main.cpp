#include <stdio.h>

#define STRINGS 5
#define ELEMENTS 8

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

int main()
{
    int matrix[STRINGS][ELEMENTS] = {
        {0, 1, 2, 2, 3, 1, 3, 3},
        {0, 3, 3, 3, 2, 2, 2, 2}, 
        {0, 5, 5, 5, 5, 5, 9, 1}, 
        {0, 0, 0, 0, 0, 0, 0, 0}, 
        {0, 7, 2, 4, 5, 6, 9, 1} };

    calculation(matrix[0]);

    int total_count[STRINGS];

    for (int i = 0; i < STRINGS; i++)
    {
        total_count[i] = calculation(matrix[i]);
    }

    for (int j = 0; j < STRINGS; j++)
    {
        printf("string N%d strike : %d\n", (j + 1), total_count[j]);
    }

    int index = 0;
    for (int k = 1; k < STRINGS; k++) 
    {
        if (total_count[k] > total_count[k - 1])
            index = k;
    }
    printf("the highest strike has string N%d: %d\n", (index + 1), total_count[index]);
    
}
