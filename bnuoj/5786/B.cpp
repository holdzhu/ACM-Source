#include <cstdio>
#include <cmath>

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	int minx = 1000000000;
	while (m--)
	{
		int u, d;
		scanf("%d %d", &u, &d);
		int t = (int)ceil((n * d + 1.0) / (u + d));
		t = t * u - (n - t) * d;
		if (minx > t)
		{
			minx = t;
		}
	}
	printf("%d\n", minx);
	return 0;
}
