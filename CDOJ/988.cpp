#include <cstdio>

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int a = 0;
		int b = 0;
		int c = 0;
		int d = 0;
		int n;
		scanf("%d", &n);
		while (n--)
		{
			int t;
			scanf("%d", &t);
			if (t < 10)
			{
				a++;
			}
			else if (t < 100)
			{
				b++;
			}
			else if (t < 1000)
			{
				c++;
			}
			else
			{
				d++;
			}
		}
		printf("%d %d %d %d\n", a, b, c, d);
	}
	return 0;
}
