#include <cstdio>

const bool d[7][7] = {
	{0, 1, 1, 1, 0, 0, 0},
	{1, 0, 1, 1, 1, 0, 0},
	{1, 1, 0, 1, 1, 0, 0},
	{1, 1, 1, 0, 1, 1, 0},
	{0, 1, 1, 1, 0, 1, 0},
	{0, 0, 0, 1, 1, 0, 1},
	{0, 0, 0, 0, 0, 1, 0}
};

int main()
{
	int a, b;
	scanf("%d %d", &a, &b);
	if (a >= 0 && b >= 0 && a <= 6 && b <= 6)
	{
		printf("%s\n", d[a][b] ? "Yes" : "No");
	}
	else
	{
		if (a - b == 1 || b - a == 1)
		{
			printf("Yes\n");
		}
		else
		{
			printf("No\n");
		}
	}
	return 0;
}
