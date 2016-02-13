#include <cstdio>

int main()
{
	freopen("grave.in", "r", stdin);
	freopen("grave.out", "w", stdout);
	int x1, y1, x2, y2, x3, y3, x4, y4;
	scanf("%d %d %d %d %d %d %d %d", &x1, &y1, &x2, &y2, &x3, &y3, &x4, &y4);
	int w, h;
	scanf("%d %d", &w, &h);
	if (w > x2 - x1 || h > y2 - y1)
		puts("No");
	else
	{
		if (x3 - x1 >= w || x2 - x4 >= w || y3 - y1 >= h || y2 - y4 >= h)
			puts("Yes");
		else
			puts("No");
	}
	return 0;
}
