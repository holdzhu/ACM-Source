#include <cstdio>

int main()
{
	int n = -1;
	char c;
	while ((c = getchar()))
	{
		if (c == '\n')
		{
			printf("%d\n", (n + 8) % 9 + 1);
			n = -1;
		}
		else
		{
			if (n == -1)
			{
				if (c == '0')
				{
					break;
				}
				else
				{
					n = 0;
				}
			}
			n += c - '0';
			n %= 9;
		}
	}
	return 0;
}
