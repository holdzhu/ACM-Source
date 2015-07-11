#include <cstdio>

char s[50];
int k[26];

int main()
{
	int T;
	scanf("%d", &T);
	for (int kase = 1; kase <= T; ++kase)
	{
		for (int i = 0; i < 26; ++i)
		{
			scanf("%d", &k[i]);
		}
		int N;
		scanf("%d", &N);
		printf("case %d:\n", kase);
		while (N--)
		{
			scanf("%s", s);
			int p = 0;
			for ( ; s[p] != '.'; ++p)
				;
			double ans = 0;
			int lp = p + 1;
			for ( ; s[lp] != '.'; ++lp)
			{
				ans += k[s[lp] - 'a'];
			}
			printf("%.2f\n", ans / (lp - p - 1));
		}
		if (kase < T)
		{
			printf("\n");
		}
	}
	return 0;
}