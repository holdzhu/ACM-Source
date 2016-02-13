#include <cstdio>

int mat[500][500];

int main()
{
	int n, k;
	scanf("%d %d", &n, &k);
	int num = n * n;
	for (int i = 0; i < n; ++i)
	{
		for (int j = n - 1; j >= k - 1; --j)
		{
			mat[i][j] = num--;
		}
	}
	for (int i = 0; i < n; ++i)
	{
		for (int j = k - 2; j >= 0; --j)
		{
			mat[i][j] = num--;
		}
	}
	long long ans = 0;
	for (int i = 0; i < n; ++i)
		ans += mat[i][k - 1];
	printf("%I64d\n", ans);
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			printf("%d%s", mat[i][j], j == n - 1 ? "\n" : " ");
		}
	}
	return 0;
}
