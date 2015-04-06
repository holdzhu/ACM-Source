#include <cstdio>

const int d[] = {1, 0, 0, -1, -1, 0, 0, 1};

int main()
{
	char s[201];
	while (scanf("%s", s) == 1)
	{
		printf("300 420 moveto\n310 420 lineto\n");
		int l = 0;
		int x = 31;
		int y = 42;
		for (int i = 0; s[i] != '\0'; ++i)
		{
			if (s[i] == 'A')
			{
				l++;
			}
			else
			{
				l += 3;
			}
			l %= 4;
			x += d[l * 2];
			y += d[l * 2 + 1];
			printf("%d %d lineto\n", x * 10, y * 10);
		}
		printf("stroke\nshowpage\n");
	}
	return 0;
}
