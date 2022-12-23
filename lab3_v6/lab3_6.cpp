#include <iostream>
#include <stdlib.h>

#define N 3
#define M 5

using namespace std;

void generate_massive(double massive[], int length, char prefix)
{
	for (int i = 0; i < length; i++)
	{
		cout << prefix << "_massive[" << i + 1 << "] -> ";
		cin >> massive[i];
	}
	system("CLS");
}

void display_massive(double massive[], int length, char prefix)
{
	cout << prefix << "_massive: " << endl;

	for (int i = 0; i < length; i++)
	{
		cout << massive[i] << " ";
	}
	cout << endl;
}

int main(void)
{
	double n_massive[N];
	double m_massive[M];

	generate_massive(n_massive, N, 'n');
	generate_massive(m_massive, M, 'm');
	display_massive(n_massive, N, 'n');
	display_massive(m_massive, M, 'm');

	cout << "result: " << endl;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cout << n_massive[i] * m_massive[j] << " ";
		}
	}

	return 0;
}
