#include <cstdio>

int main()
{
	long long a[18][18];
	a[0][0] = 1;
	for (int i = 1; i < 18; ++i)
	{
		a[i][0] = a[i - 1][0] * i;
		for (int j = 1; j <= i; ++j)
		{
			a[i][j] = a[i][j - 1] - a[i - 1][j - 1];
		}
	}
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int K, n, k;
		scanf("%d%d%d", &K, &n, &k);
		printf("%d %I64d\n", K, a[n][k]);
	}
	return 0;
}
