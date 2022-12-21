#include <iostream>

using namespace std;

void generate_sizes(int&, int&);
void generate_matrix(int**&, int&, int&);
void add_elements(int**&, int&, int&);
void display_matrix(int**&, int, int);
int calculation(int*&, int);
void add_strikes(int*&, int**&, int, int);
void display_strikes(int*&, int);
void display_highest_row(int*&, int);

int main(void)
{
	int** matrix;
	int rows, columns;
	generate_sizes(rows, columns);
	int* total_count = new int[rows];

	generate_matrix(matrix, rows, columns);
	add_elements(matrix, rows, columns);
	display_matrix(matrix, rows, columns);
	calculation(matrix[0], columns);
	add_strikes(total_count, matrix, rows, columns);
	display_strikes(total_count, rows);
	display_highest_row(total_count, rows);

	return 0;
}

void generate_sizes(int& rows, int& columns)
{
	do
	{
		cout << "input rows -> ";
		cin >> rows;
	} while (rows < 0);
	do
	{
		cout << "input rows -> ";
		cin >> columns;
	} while (columns < 0);
}

void generate_matrix(int**& matrix, int& rows, int& columns)
{
	matrix = new int* [rows];
	for (int i = 0; i < rows; i++)
		*(matrix + i) = new int[columns];

	system("CLS");
}

void add_elements(int**& matrix, int& rows, int& columns)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			cout << "(" << i + 1 << ")(" << j + 1 << ") -> ";
			cin >> *(*(matrix + i) + j);
		}
		system("CLS");
	}
}

void display_matrix(int**& matrix, int rows, int columns)
{
	cout << "matrix:" << endl;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
			cout << matrix[i][j] << " ";
		
		cout << endl;
	}
	cout << endl;
}

int calculation(int*& str, int columns)
{
	int counter = 1;
	int highest = 0;

	for (int i = 1; i < columns; i++)
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

void add_strikes(int*& total_count, int**& matrix, int rows, int columns)
{
	for (int i = 0; i < rows; i++)
	{
		total_count[i] = calculation(matrix[i], columns);
	}
}

void display_strikes(int*& total_count, int rows)
{
	for (int j = 0; j < rows; j++)
		cout << "row N" << j + 1 << "strike : " << total_count[j] << endl;
}

void display_highest_row(int*& total_count, int rows)
{
	int index = 0;
	for (int k = 1; k < rows; k++)
	{
		if (total_count[k] > total_count[k - 1])
			index = k;
	}
	cout << "\nthe highest strike has row N" << index + 1 << ": " << total_count[index] << endl;
}
