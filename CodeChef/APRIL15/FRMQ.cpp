#include <cstdio>

int rmq[200000][20];

inline int max(int a, int b)
{
	return a > b ? a : b;
}

int main()
{
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; ++i)
	{
		scanf("%d", &rmq[i][0]);
	}
	for (int i = 1; 1 << i <= N; ++i)
	{
		for (int j = 0; j <= N - (1 << i); ++j)
		{
			rmq[j][i] = max(rmq[j][i - 1], rmq[j + (1 << (i - 1))][i - 1]);
		}
	}
	int M, x, y;
	scanf("%d %d %d", &M, &x, &y);
	long long ans = 0;
	while (M--)
	{
		int r = max(x, y);
		int l = x + y - r;
		int q;
		for (q = 0; 1 << (q + 1) <= r - l + 1; ++q);
		ans += max(rmq[l][q], rmq[r + 1 - (1 << q)][q]);
		x = (x + 7) % (N - 1);
		y = (y + 11) % N;
	}
	printf("%lld\n", ans);
	return 0;
}
