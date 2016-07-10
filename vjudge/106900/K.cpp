#include <cstdio>

int gcd(int a, int b)
{
	return b ? gcd(b, a % b) : a;
}

int main()
{
	freopen("kids.in", "r", stdin);
	freopen("kids.out", "w", stdout);
	int a, b, c, d;
	scanf("%d %d %d %d", &a, &b, &c, &d);
	int g = gcd(b, c);
	int x = c / g;
	int y = b / g;
	int t = g;
	while ((x * t % 2 && a % 2) || (y * t % 2 && d % 2) || x * t <= a || y * t <= d)
		++t;
	x *= t;
	y *= t;
	printf("%d %d\n", x, y);
	if (x % 2 == 0 && a % 2)
	{
		for (int i = 0; i < x / 2; ++i)
			printf("%d %d\n", i + 1, (i + x / 2) % x + 1);
		--a;
	}
	if (y % 2 == 0 && d % 2)
	{
		for (int i = 0; i < y / 2; ++i)
			printf("%d %d\n", x + i + 1, x + (i + y / 2) % y + 1);
		--d;
	}
	for (int i = 1; i <= x / 2 && 2 * i <= a; ++i)
		for (int j = 0; j < x; ++j)
			printf("%d %d\n", j + 1, (j + i) % x + 1);
	for (int i = 1; i <= y / 2 && 2 * i <= d; ++i)
		for (int j = 0; j < y; ++j)
			printf("%d %d\n", x + j + 1, x + (j + i) % y + 1);
	for (int i = 0, j = 0; i < x; ++i)
		for (int k = 0; k < b; ++k, j = (j + 1) % y)
			printf("%d %d\n", i + 1, x + j + 1);
	return 0;
}
