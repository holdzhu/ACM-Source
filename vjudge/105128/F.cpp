#include <cstdio>

int main()
{
	int n, m, a, b;
	scanf("%d %d %d %d", &n, &m, &a, &b);
	if (b == n)
		b = (n + m - 1) / m * m;
	a--, b--;
	int ra = a / m;
	int ca = a % m;
	int rb = b / m;
	int cb = b % m;
	if (ra == rb || (ca == 0 && cb == m - 1))
		puts("1");
	else if (ra + 1 == rb || ca == 0 || cb == m - 1 || ca - 1 == cb)
		puts("2");
	else
		puts("3");
	return 0;
}
