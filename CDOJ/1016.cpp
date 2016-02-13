#include <cstdio>

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int m;
		scanf("%d", &m);
		int n;
		scanf("%d", &n);
		int s = n;
		while (--m)
		{
			int t;
			scanf("%d", &t);
			s += t;
		}
		printf("%.5f\n", 1.0 * n / s);
	}
	return 0;
}
