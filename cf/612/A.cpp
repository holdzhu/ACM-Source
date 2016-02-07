#include <cstdio>

char s[101];

int main()
{
	int n, p, q;
	scanf("%d %d %d", &n, &p, &q);
	scanf("%s", s);
	int flag = -1;
	for (int i = 0; i * p <= n; ++i)
	{
		if ((n - i * p) % q == 0)
		{
			flag = i;
			break;
		}
	}
	if (flag == -1)
	{
		puts("-1");
	}
	else
	{
		printf("%d\n", flag + (n - flag * p) / q);
		int j = 0;
		for (int i = 0; i < flag; ++i)
		{
			for (int k = 0; k < p; ++k)
			{
				putchar(s[j++]);
			}
			puts("");
		}
		for (int i = 0; i < (n - flag * p) / q; ++i)
		{
			for (int k = 0; k < q; ++k)
			{
				putchar(s[j++]);
			}
			puts("");
		}
	}
	return 0;
}
