#include <cstdio>

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		char s[201];
		scanf("%s", s);
		char n[201];
		int p = 0;
		for (int i = 0; s[i] != '\0'; ++i)
		{
			if (s[i] >= '0' && s[i] <= '9')
			{
				n[p++] = s[i];
			}
		}
		for (int i = 0; i < (p - 1) % 4 + 1; ++i)
		{
			putchar(n[i]);
		}
		for (int i = (p - 1) % 4 + 1; i < p; i += 4)
		{
			putchar(',');
			putchar(n[i]);
			putchar(n[i + 1]);
			putchar(n[i + 2]);
			putchar(n[i + 3]);
		}
		putchar('\n');
	}
	return 0;
}
