#include <cstdio>

int main()
{
	freopen("garage.in", "r", stdin);
	freopen("garage.out", "w", stdout);
	int W, H, w, h;
	scanf("%d %d %d %d", &W, &H, &w, &h);
	printf("%d\n", ((W + w) / (w * 2)) * ((H + h) / (h * 2)));
	return 0;
}
