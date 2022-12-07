#include <iostream>
using namespace std;

int scan_elements(int list[], int length)
{
	int element;
	for (int i = 0; i < length; i++)
	{
		printf("input: ");
		scanf_s("%d", &element);
		list[i] = element;
	}
	return 0;
}

int main()
{
	const int m = 5;
	const int n = 5;

	int m_array[m];
	int n_array[n];
	int new_array[m > n ? m : n];

	printf("scan m array\n"); 
	scan_elements(m_array, m);
	printf("\033[2J\033[1;1H"); //clear console
	printf("scan n array\n");
	scan_elements(n_array, n);
	printf("\033[2J\033[1;1H"); //clear console

	
	for (int j = 0; j < (m > n ? m : n); j++)
	{
		for (int i = 0; i < (m < n ? m : n); i++)
		{
			if(i == 0)
				new_array[j] = (m < n ? m_array[i] : n_array[i]) * (m > n ? m_array[j] : n_array[j]);
			else
				new_array[j] += (m < n ? m_array[i] : n_array[i]) * (m > n ? m_array[j] : n_array[j]);
		}
	}


	for (int k = 0; k < sizeof(new_array) / sizeof(new_array[0]); k++)
		printf("%d ", new_array[k]);

	return 0;
}