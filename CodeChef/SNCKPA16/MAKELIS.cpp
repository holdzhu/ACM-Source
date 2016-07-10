#include <cstdio>

int cnt[100];

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int N;
		scanf("%d", &N);
		if (N == 1)
		{
			puts("1\n1");
			continue;
		}
		int l = 0;
		while (1 << (l + 1) <= N)
			++l;
		int n = l * 2;
		int v = 1;
		for (int i = 0; i < l; ++i)
		{
			if (N >> i & 1)
				for (int j = i + 1; j <= l; ++j)
					if (N >> j & 1)
					{
						for (int k = 0; k < j - i; ++k)
							cnt[n++] = v++;
						break;
					}
			cnt[i * 2 + 1] = v++;
			cnt[i * 2] = v++;
		}
		printf("%d\n", n);
		for (int i = 0; i < n; ++i)
			printf("%d%c", cnt[i], "\n "[i < n - 1]);
	}
	return 0;
}