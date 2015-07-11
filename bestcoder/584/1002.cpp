#include <cstdio>
#include <cstring>

char s[100001];
int K;

int main()
{
	int T;
	scanf("%d", &T);
	for (int kase = 0; kase < T; ++kase)
	{
		do
		{
			gets(s);
		}
		while (s[0] == 0);
		scanf("%d", &K);
		int l = strlen(s);
		int line = (l - 1) / K;
		int remain = l - line * K;
		printf("Case #%d:\n", kase + 1);
		for (int i = 0; i < line; ++i)
		{
			for (int j = 0; j < K; ++j)
			{
				if (j < remain)
				{
					putchar(s[j * (line + 1) + i]);
				}
				else
				{
					putchar(s[remain * (line + 1) + (j - remain) * line + i]);
				}
			}
		}
		for (int i = 0; i < remain; ++i)
		{
			putchar(s[i * (line + 1) + line]);
		}
		putchar('\n');
	}
	return 0;
}
