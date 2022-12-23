#include <iostream>
#include <cmath>

using namespace std;

int main(void)
{
	double a;
	cout << "input a -> ";
	cin >> a;

	double b;
	cout << "input b -> ";
	cin >> b;

	int n = 0;
	while (n <= 0)
	{
		cout << "input n -> ";
		cin >> n;
	}

	double h = (b - a) / n;
	int i = 0;
	double x = a + i * h;
	double x_min = x;
	double x_max = x;
	double y = tan(x) + atan(1 - x*x);
	double y_min = y;
	double y_max = y;

	cout << "\nx: " << x << endl << "y: " << y << endl;

	while (i < n)
	{
		i++;
		x = a + i * h;
		y = tan(x) + atan(1 - x * x);
		cout << "\nx: " << x << endl << "y: " << y << endl;
		if (y > y_max)
		{
			y_max = y;
			x_max = x;
		}
		else
		{
			y_min = y;
			x_min = x;
		}
	}

	cout << "\nx: " << x << endl << "y: " << y << endl;
	cout << "x_max: " << x_max << endl << "y_max: " << y_max << endl;
	cout << "x_min: " << x_min << endl << "y_min: " << y_min << endl;

	return 0;
}
