#include <cstdio>

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		int s = a * b;
		while (b)
		{
			int t = a % b;
			a = b;
			b = t;
		}
		printf("%d %d\n", a, s / a);
	}
	return 0;
}
