#include <cstdio>

const int d[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

int main()
{
	int a, b;
	scanf("%d %d", &a, &b);
	int ans = 0;
	for (int i = a; i <= b; ++i)
	{
		int t = i;
		while (t)
		{
			ans += d[t % 10];
			t /= 10;
		}
	}
	printf("%d\n", ans);
	return 0;
}
