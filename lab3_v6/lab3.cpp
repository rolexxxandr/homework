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
	const int n = 3;

	int m_array[m];
	int n_array[n];
	int new_array[m > n ? m : n];

	printf("scan m array\n");
	scan_elements(m_array, m);
	printf("scan n array\n");
	scan_elements(n_array, n);
	
	int smaller_array = (m < n ? 0 : 1);
	int i = 0;

	while (i < (m > n ? m : n))
	{
		if (i+1 > (m < n ? m : n) && smaller_array == 0)
			new_array[i] = n_array[i];
		else if (i+1 > (m < n ? m : n) && smaller_array == 1)
			new_array[i] = m_array[i];
		else
			new_array[i] = n_array[i] * m_array[i];
		i++;
	}

	for (int j = 0; j < sizeof(new_array)/sizeof(new_array[0]); j++)
		printf("%d) %d\n", j, new_array[j]);
	
	return 0;
}