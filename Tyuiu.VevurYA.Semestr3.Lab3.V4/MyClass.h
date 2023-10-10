#pragma once
using namespace std;


class my_Fun
{
	double x, y, z, w;

public:

	void set(double X, double Y, double Z)
	{
		x = X * pow(10, 4);
		y = Y;
		z = Z * pow(10, -3);
	}

	void run()
	{
		w = (pow(abs(cos(x) - cos(y)), (1 + 2 * pow(sin(y), 2)))) * (1 + z + pow(z, 2) / 2 + pow(z, 3) / 4 + pow(z, 4) / 4);
	}

	void print()
	{
		cout << w << endl;
	}
};