#include <cstdio>

int gcd(int a, int b)
{
	return b == 0 ? a : gcd(b, a % b);
}

int lcm(int a, int b)
{
	return a / gcd(a, b) * b;
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int n;
		scanf("%d", &n);
		int t;
		int s;
		scanf("%d", &s);
		for (int i = 1; i < n; ++i)
		{
			scanf("%d", &t);
			s = lcm(s, t);
		}
		printf("%d\n", s);
	}
	return 0;
}
