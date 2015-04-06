#include <cstdio>

int main()
{
	int T;
	scanf("%d", &T);
	for (int _T = 0; _T < T; ++_T)
	{
		int k[26];
		for (int i = 0; i < 26; ++i)
		{
			scanf("%d", &k[i]);
		}
		int N;
		scanf("%d", &N);
		char s[50];
		if (_T)
		{
			putchar('\n');
			putchar('\n');
			putchar('\n');
		}
		printf("case %d:\n", _T + 1);
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
			printf("%.2lf", ans / (lp - p - 1));
			if (N)
			{
				putchar('\n');
			}
		}
	}
	return 0;
}
