#include <cstdio>
#include <cstring>

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int n;
		scanf("%d", &n);
		int s[101];
		memset(s, 0, sizeof(s));
		for (int i = 0; i < n; ++i)
		{
			int t;
			scanf("%d", &t);
			s[t]++;
		}
		int sum[102];
		sum[0] = 0;
		for (int i = 0; i < 101; ++i)
		{
			sum[i + 1] = sum[i] + s[i];
		}
		int m;
		scanf("%d", &m);
		while (m--)
		{
			int a, b;
			scanf("%d %d", &a, &b);
			printf("%d\n", sum[b + 1] - sum[a]);
		}
		putchar('\n');
	}
	return 0;
}
