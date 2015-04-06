#include <cstdio>

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int x1, y1, x2, y2, x3, y3;
		scanf("%d %d %d %d %d %d", &x1, &y1, &x2, &y2, &x3, &y3);
		int a1x = x1 - x2;
		int a1y = y1 - y2;
		int a2x = x2 - x3;
		int a2y = y2 - y3;
		int a3x = x3 - x1;
		int a3y = y3 - y1;
		if (a1x * a2x + a1y * a2y == 0)
		{
			printf("%d %d\n", x1 + x3 - x2, y1 + y3 - y2);
		}
		else if (a1x * a3x + a1y * a3y == 0)
		{
			printf("%d %d\n", x2 + x3 - x1, y2 + y3 - y1);
		}
		else
		{
			printf("%d %d\n", x2 + x1 - x3, y2 + y1 - y3);
		}
	}
	return 0;
}
