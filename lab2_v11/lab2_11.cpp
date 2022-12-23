#include <iostream>
#include <cmath>

using namespace std;

int main(void)
{
	double E = 0.001;
	double x = 0.57;
	int i = 2;
	double e = exp(1);
	double S = (-1) * (x / e);
	double a = (-1) * (x / e) * (1 + pow(1.0 / i - 1, i - 1));

	while (a*-1 > E)
	{
		i++;
		a = (-1) * (x / e) * (1 + pow(1.0 / i - 1, i - 1));
		cout << i << endl;
		cout << "a: " << a << endl;
	}

	cout << a << endl;
	cout << i << endl;

	return 0;
}
