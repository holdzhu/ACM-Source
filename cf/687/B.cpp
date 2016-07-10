#include <cstdio>

int gcd(int a, int b)
{
	return b ? gcd(b, a % b) : a;
}

int lcm(int a, int b)
{
	return a / gcd(a, b) * b;
}

int main()
{
	int n, k;
	scanf("%d %d", &n, &k);
	int l = 1;
	for (int i = 0; i < n; ++i)
	{
		int u;
		scanf("%d", &u);
		u = gcd(u, k);
		l = lcm(l, u);
	}
	puts(l == k ? "Yes" : "No");
	return 0;
}
