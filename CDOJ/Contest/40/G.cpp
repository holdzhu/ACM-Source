#include <cstdio>

int main()
{
	int T;
	scanf("%d", &T);
	long long a[100], b[100], c[100];
	a[0] = 0;
	b[0] = 0;
	c[0] = 1;
	a[1] = 1;
	b[1] = 1;
	c[1] = 1;
	for (int i = 2; i < 100; ++i)
	{
		a[i] = c[i - 1] % 1000000009;
		b[i] = (b[i - 1] + c[i - 1]) % 1000000009;
		c[i] = (a[i - 1] + b[i - 1] + c[i - 1]) % 1000000009;
	}
	while (T--)
	{
		int n;
		scanf("%d", &n);
		printf("%lld\n", (a[n - 1] + b[n - 1] * 2 + c[n - 1] * 3) % 1000000009);
	}
	return 0;
}
