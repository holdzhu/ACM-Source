#include <cstdio>

int main()
{
	int w;
	scanf("%d", &w);
	puts(w % 2 == 0 && w / 2 > 1 ? "YES" : "NO");
	return 0;
}
