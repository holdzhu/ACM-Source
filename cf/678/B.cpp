#include <cstdio>

int get(int x)
{
	int leap = x / 4 + x / 400 - x / 100;
	return (1ll * leap * 366 + 1ll * (x - leap) * 365) % 7;
}

bool b(int x)
{
	return x % 400 == 0 || (x % 100 && x % 4 == 0);
}

int main()
{
	int y;
	scanf("%d", &y);
	int x = y + 1;
	while (get(x) != get(y) || b(x) != b(y))
		x++;
	printf("%d\n", x);
	return 0;
}
