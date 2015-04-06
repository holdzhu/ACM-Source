#include <cstdio>

inline int max(int a, int b)
{
	return a > b ? a : b;
}

int main()
{
	int N;
	scanf("%d", &N);
	int a[N][N];
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j <= i; ++j)
		{
			scanf("%d", &a[i][j]);
		}
	}
	for (int i = N - 2; i >= 0; --i)
	{
		for (int j = 0; j < i + 1; ++j)
		{
			a[i][j] += max(a[i + 1][j], a[i + 1][j + 1]);
		}
	}
	printf("%d\n", a[0][0]);
	return 0;
}
