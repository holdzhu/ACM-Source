#include <cstdio>
#include <cstdlib>

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int n;
		scanf("%d", &n);
		int **a;
		a = (int **)malloc(sizeof(int *) * n);
		for (int i = 0; i < n; ++i)
		{
			a[i] = (int *)malloc(sizeof(int) * n);
			for (int j = 0; j < n; ++j)
			{
				a[i][j] = i * n + j + 1;
			}
		}
		long long s1 = 0; 
		int s2 = 0; 
		int s3 = 0; 
		for (int i = 1; i < n - 1; ++i)
		{
			for (int j = 1; j < n - 1; ++j)
			{
				s1 += a[i][j];
			}
		}
		for (int i = 0; i < n; ++i)
		{
			s2 += a[i][i];
		}
		for (int i = 0; i < n; ++i)
		{
			s3 += a[n - i - 1][i];
		}
		printf("%lld %d %d\n", s1, s2, s3);
	}
	return 0;
}
