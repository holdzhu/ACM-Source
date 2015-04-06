#include <cstdio>

int main()
{
	bool odd = true;
	char c;
	while ((c = getchar()) != EOF)
	{
		if (c >= 'a' && c <= 'z')
		{
			if (odd)
			{
				putchar(c - 'a' + 'A');
			}
			else
			{
				putchar(c);
			}
			odd = !odd;
		}
		else if (c >= 'A' && c <= 'Z')
		{
			if (odd)
			{
				putchar(c);
			}
			else
			{
				putchar(c - 'A' + 'a');
			}
			odd = !odd;
		}
		else if (c != '\n')
		{
			putchar(c);
			odd = !odd;
		}
		else
		{
			putchar(c);
		}
	}
	return 0;
}
