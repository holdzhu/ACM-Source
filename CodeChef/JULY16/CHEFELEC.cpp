#include <cstdio>

char s[100001];
int x[100001];

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int N;
		scanf("%d", &N);
		scanf("%s", s);
		for (int i = 0; i < N; ++i)
			scanf("%d", &x[i]);
		int ans = x[N - 1] - x[0];
		for (int i = 0, first = 1, mx = -1; i < N; ++i)
		{
			if (s[i] == '1')
			{
				if (!first)
					ans -= mx;
				first = 0;
				mx = -1;
			}
			if (i + 1 < N && x[i + 1] - x[i] >= mx)
				mx = x[i + 1] - x[i];
		}
		printf("%d\n", ans);
	}
	return 0;
}
