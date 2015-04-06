#include <cstdio>

int main()
{
	int n;
	scanf("%d", &n);
	char s[n + 1];
	scanf("%s", s);
	long long ans = 1;
	int c[4] = {0, 0, 0, 0};
	for (int i = 0; i < n; ++i)
	{
		if (s[i] == 'A')
		{
			c[0]++;
		}
		else if (s[i] == 'C')
		{
			c[1]++;
		}
		else if (s[i] == 'G')
		{
			c[2]++;
		}
		else if (s[i] == 'T')
		{
			c[3]++;
		}
	}
	int maxc = 0;
	int maxcc = 0;
	for (int i = 0; i < 4; ++i)
	{
		if (c[i] > maxc)
		{
			maxc = c[i];
			maxcc = 1;
		}
		else if (c[i] == maxc)
		{
			maxcc++;
		}
	}
	for (int i = 0; i < n; ++i)
	{
		ans *= maxcc;
		ans %= 1000000007;
	}
	printf("%I64d\n", ans);
	return 0;
}
