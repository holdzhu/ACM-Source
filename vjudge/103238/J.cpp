#include <cstdio>

int x[100];
bool s[100];

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int n, D;
		scanf("%d %d", &n, &D);
		for (int i = 0; i < n; ++i)
			scanf("%d", &x[i]);
		int ans = 1e9;
		for (int i = 0; i < (1 << D); ++i)
		{
			bool c = 0;
			int cnt = 0;
			for (int j = 0; j < D && j < n; ++j)
				c ^= s[j] = i >> j & 1;
			for (int j = 0; j < n; ++j)
			{
				if (j > D)
					c ^= s[j - D - 1];
				if (j + D < n)
					c ^= s[j + D] = c ^ x[j];
				else if (c ^ x[j])
					goto failed;
			}
			for (int j = 0; j < n; ++j)
				cnt += s[j];
			if (cnt < ans)
				ans = cnt;
			failed:;
		}
		if (ans <= n)
			printf("%d\n", ans);
		else
			puts("impossible");
	}
	return 0;
}
