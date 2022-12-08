#include <stdio.h>

#define STRINGS 5
#define ELEMENTS 8

int calculation(int str[ELEMENTS])
{
    int elements[ELEMENTS];
    int count[ELEMENTS];
    int counter = 1;
    
    elements[0] = str[0];

    for (int i = 1; i < ELEMENTS; i++)
    {
        if (str[i] == str[i - 1])
            counter++;
        else
        {
            count[i - 1] = counter;
            counter = 1;
            elements[i] = str[i];
        }
    }
    count[ELEMENTS - 1] = counter;

    for (int i = 0; i < ELEMENTS; i++)
    {
        printf("%d - %d\n", elements[i], count[i]);
    }
    
    return 0;
}

int main()
{
    int matrix[STRINGS][ELEMENTS] = {
        {0, 1, 2, 2, 1, 3, 3, 3},
        {0, 7, 2, 4, 5, 6, 9, 1}, 
        {0, 7, 2, 4, 5, 6, 9, 1}, 
        {0, 7, 2, 4, 5, 6, 9, 1}, 
        {0, 7, 2, 4, 5, 6, 9, 1} };

    calculation(matrix[0]);

    int total_count[STRINGS];
}
