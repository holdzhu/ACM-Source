#include <cstdio>
#include <cstring>

const int p[10][4] = {
	{0, 0, 0, 0},
	{0, 0, 0, 0},
	{1, 0, 0, 0},
	{1, 1, 0, 0},
	{3, 1, 0, 0},
	{3, 1, 1, 0},
	{4, 2, 1, 0},
	{4, 2, 1, 1},
	{7, 2, 1, 1},
	{7, 4, 1, 1}
};

int main()
{
	int n;
	scanf("%d", &n);
	char s[n + 1];
	scanf("%s", s);
	int sp[4];
	memset(sp, 0, sizeof(sp));
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			sp[j] += p[s[i] - '0'][j];
		}
	}
	while (sp[3])
	{
		putchar('7');
		sp[0] -= 4;
		sp[1] -= 2;
		sp[2] -= 1;
		sp[3] -= 1;
	}
	while (sp[2])
	{
		putchar('5');
		sp[0] -= 3;
		sp[1] -= 1;
		sp[2] -= 1;
	}
	while (sp[1])
	{
		putchar('3');
		sp[0] -= 1;
		sp[1] -= 1;
	}
	while (sp[0])
	{
		putchar('2');
		sp[0] -= 1;
	}
	printf("\n");
	return 0;
}
