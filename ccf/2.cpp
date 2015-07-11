#include <cstdio>

const int pos[] = {0, 2, 3, 4, 6, 7, 8, 9, 10};
char s[14];

int idx(char c)
{
	if (c >= '0' && c <= '9')
	{
		return c - '0';
	}
	return 10;
}

char deidx(int x)
{
	if (x < 10)
	{
		return '0' + x;
	}
	return 'X';
}

int main()
{
	scanf("%s", s);
	int sum = 0;
	for (int i = 0; i < 9; ++i)
	{
		sum += idx(s[pos[i]]) * (i + 1);
	}
	if (sum % 11 == idx(s[12]))
	{
		printf("Right\n");
	}
	else
	{
		printf("%.12s%c\n", s, deidx(sum % 11));
	}
	return 0;
}
