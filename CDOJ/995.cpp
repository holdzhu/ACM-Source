#include <cstdio>

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int n;
		char ch;
		scanf(" %d %c", &n, &ch);
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < i + 1; ++j)
			{
				putchar(ch);
			}
			for (int j = 0; j < (n - i - 1) * 2; ++j)
			{
				putchar(' ');
			}
			for (int j = 0; j < i + 1; ++j)
			{
				putchar(ch);
			}
			putchar('\n');
		}
		for (int i = n - 2; i >= 0; --i)
		{
			for (int j = 0; j < i + 1; ++j)
			{
				putchar(ch);
			}
			for (int j = 0; j < (n - i - 1) * 2; ++j)
			{
				putchar(' ');
			}
			for (int j = 0; j < i + 1; ++j)
			{
				putchar(ch);
			}
			putchar('\n');
		}
		putchar('\n');
	}
	return 0;
}
