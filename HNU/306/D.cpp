#include <cstdio>

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int K, n;
		scanf("%d%d", &K, &n);
		int a = 1;
		int b = 1;
		int c;
		for (c = 1; ; ++c)
		{
			int t = a;
			a = b;
			b += t;
			a %= n;
			b %= n;
			if (a == 1 && b == 1)
			{
				break;
			}
		}
		printf("%d %d\n", K, c);
	}
	return 0;
}
