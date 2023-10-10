#pragma once
using namespace std;

class my_Fun
{
	double x, y, z, h;

public:

	void set(double X, double Y, double Z)
	{
		x = X;
		y = Y * pow(10, -2);;
		z = Z * pow(10, 3);
	}

	void run()
	{
		h = ((pow(x,y+1)+exp(y-1))/(1+x*abs(y-tan(z))))*(1+abs(y-x))+(pow(abs(y-x),2)/2)-(pow(abs(y-x),3)/3);
	}

	void print()
	{
		cout << h << endl;
	}
};