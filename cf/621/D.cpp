#include <cstdio>
#include <cmath>

const char s[12][10] = {"x^y^z", "x^z^y", "(x^y)^z", "(x^z)^y", "y^x^z", "y^z^x", "(y^x)^z", "(y^z)^x", "z^x^y", "z^y^x", "(z^x)^y", "(z^y)^x"};
double d[12];

int main()
{
	double x, y, z;
	scanf("%lf %lf %lf", &x, &y, &z);
	d[0] = pow(y, z) * log(x);
	d[1] = pow(z, y) * log(x);
	d[2] = d[3] = y * z * log(x);
	d[4] = pow(x, z) * log(y);
	d[5] = pow(z, x) * log(y);
	d[6] = d[7] = x * z * log(y);
	d[8] = pow(x, y) * log(z);
	d[9] = pow(y, x) * log(z);
	d[10] = d[11] = x * y * log(z);
	int mx = 0;
	for (int i = 1; i < 12; ++i)
		if (d[i] > d[mx])
			mx = i;
	puts(s[mx]);
	return 0;
}
