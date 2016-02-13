#include <cstdio>

int m, n, x1, y1, x2, y2, p, q;

int gcd(int a, int b)
{
	return b ? gcd(b, a % b) : a;
}

int gcd(int a, int b, int& x, int& y)
{
	if (!b)
	{
		x = 1;
		y = 0;
		return a;
	}
	int d = gcd(b, a % b, y, x);
	y -= x * (a / b);
	return d;
}

bool solve(int x, int y)
{
	int d1, d2;
	int t, t1, t2;
	d1 = gcd(p, m, t1, t);
	d2 = gcd(q, n, t2, t);
	if (x % d1 != 0 || y % d2 != 0)
		return false;
	t1 *= x / d1;
	t2 *= y / d2;
	return (t1 - t2) % gcd(m / d1, n / d2) == 0;
}

int main()
{
	while (scanf("%d %d %d %d %d %d %d %d", &m, &n, &x1, &y1, &x2, &y2, &p, &q) == 8 && m)
	{
		m <<= 1;
		n <<= 1;
		int g = gcd(p, q);
		p /= g;
		q /= g;
		puts(solve(x2 - x1, y2 - y1) || solve(m - x2 - x1, y2 - y1) ||
			solve(x2 - x1, n - y2 - y1) || solve(m - x2 - x1, n - y2 - y1) ? "HIT" : "MISS");
	}
	return 0;
}
