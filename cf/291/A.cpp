#include <cstdio>

int main()
{
	char s[20];
	scanf("%s", s);
	for (int i = 0; s[i] != '\0'; ++i)
	{
		if (s[i] == '9' && i == 0)
		{
			putchar(s[i]);
		}
		else if (s[i] >= '5')
		{
			putchar(9 - s[i] + '0' * 2);
		}
		else
		{
			putchar(s[i]);
		}
	}
	putchar('\n');
	return 0;
}
