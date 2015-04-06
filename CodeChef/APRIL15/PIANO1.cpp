#include <cstdio>
#include <cstring>

char s[101];

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%s", s);
		int l = strlen(s);
		int n;
		scanf("%d", &n);
		n *= 12;
		int c = 0;
		for (int i = 0; i < l; ++i)
		{
			if (s[i] == 'T')
			{
				c += 2;
			}
			else
			{
				c++;
			}
		}
		int ans = 0;
		for (int i = 1; i <= n / c; ++i)
		{
			ans += n - i * c;
		}
		printf("%d\n", ans);
	}
	return 0;
}
