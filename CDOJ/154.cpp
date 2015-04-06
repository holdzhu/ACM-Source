#include <cstdio>

int main()
{
	int N, L, V;
	while (scanf("%d %d %d", &N, &L, &V) == 3 && N && L && V)
	{
		int maxl = 0;
		int a = 0;
		while (N--)
		{
			int p;
			char s, d;
			scanf("%d %c %c", &p, &s, &d);
			if (d == 'E')
			{
				p = L - p;
			}
			a += p;
			if (p > maxl)
			{
				maxl = p;
			}
		}
		printf("%.2lf %.2lf\n", maxl * 1.0 / V, a * 1.0);
	}
	return 0;
}
