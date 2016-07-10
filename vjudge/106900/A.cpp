#include <cstdio>

char s[101];
bool ch[27];

int main()
{
	freopen("arrange.in", "r", stdin);
	freopen("arrange.out", "w", stdout);
	int n;
	scanf("%d", &n);
	while (n--)
	{
		scanf("%s", s);
		ch[s[0] - 'A'] = 1;
	}
	for (int i = 0; ; ++i)
	{
		if (!ch[i])
		{
			printf("%d\n", i);
			return 0;
		}
	}
}
