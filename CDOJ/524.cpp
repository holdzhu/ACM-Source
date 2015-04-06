#include <cstdio>

int main()
{
	char s[101];
	scanf("%s", s);
	int n;
	scanf("%d", &n);
	while (n--)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		for (int i = a; i < a + b && *(s + i) != '\0'; ++i)
		{
			if (i >= 0)
			{
				putchar(*(s + i));
			}
		}
		putchar('\n');
	}
	return 0;
}
