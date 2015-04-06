#include <cstdio>

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int h1, m1, h2, m2;
		scanf("%d %d %d %d", &h1, &m1, &h2, &m2);
		printf("%d\n", (h2 * 60 + m2) * 11 / 720 - (h1 * 60 + m1) * 11 / 720);
	}
	return 0;
}
