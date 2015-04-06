#include <cstdio>

long long a[1000001];

int main()
{
	a[0] = 1;
	a[1] = 1;
	a[2] = 2;
	for (int i = 3; i < 1000001; ++i)
	{
		a[i] = a[i - 2] + a[i - 3];
		a[i] %= 1000000007;
	}
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int n;
		scanf("%d", &n);
		printf("%lld\n", a[n]);
	}
	return 0;
}
