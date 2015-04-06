#include <cstdio>

int main()
{
	char s[101];
	while (scanf("%s", s) == 1)
	{
		bool is = false;
		bool ha = false;
		for (int i = 0; s[i] != '\0'; ++i)
		{
			if (s[i] == '/')
			{
				is = false;
			}
			else
			{
				if (is == false)
				{
					putchar('/');
				}
				putchar(s[i]);
				is = true;
				ha = true;
			}
		}
		if (!ha)
		{
			putchar('/');
		}
		putchar('\n');
	}
	return 0;
}
