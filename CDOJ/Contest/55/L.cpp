#include <cstdio>
#include <cmath>

void swap(int &a, int &b)
{
	a ^= b;
	b ^= a;
	a ^= b;
}

int main()
{
	int a1, a2, b1, b2, c1, c2;
	scanf("%d %d %d %d %d %d", &a1, &b1, &c1, &a2, &b2, &c2);
	if (a1 < 0)
	{
		swap(a1, a2);
		swap(b1, b2);
		swap(c1, c2);
	}
	int a = a1 - a2;
	int b = b1 - b2;
	int c = c1 - c2;
	int d = b * b - 4 * a * c;
	if (d <= 0)
	{
		printf("0.000\n");
	}
	else
	{
		double x1 = (-b + sqrt(d)) / 2 / a;
		double x2 = (-b - sqrt(d)) / 2 / a;
		printf("%.3f\n", (1.0 / 3 * a * x2 * x2 * x2 + 1.0 / 2 * b * x2 * x2 + c * x2) - (1.0 / 3 * a * x1 * x1 * x1 + 1.0 / 2 * b * x1 * x1 + c * x1));
	}
	return 0;
}
