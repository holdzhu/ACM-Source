#include <cstdio>

double (*f[])(double, double) = {
	[](double a, double b){return a + b;},
	[](double a, double b){return a - b;},
	[](double a, double b){return b - a;},
	[](double a, double b){return a * b;},
	[](double a, double b){return a / b;},
	[](double a, double b){return b / a;}
};

void 

int main()
{
	printf("%.2f\n", f[3](2, 3)); //6.00
	return 0;
}
