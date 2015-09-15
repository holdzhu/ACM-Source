#include <cstdio>
#include <cmath>
#include <cstring>

const double pi = acos(-1);
int m[360];

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		memset(m, 0, sizeof m);
		int n;
		scanf("%d", &n);
		while (n--)
		{
			int r;
			int a, b;
			scanf("%d %d %d", &r, &a, &b);
			for (int i = a; i < b; ++i)
			{
				if (m[i + 90] < r)
				{
					m[i + 90] = r;
				}
			}
		}
		double ans = 0;
		for (int i = 0; i < 360; ++i)
		{
			ans += pi * m[i] * m[i] / 360;
		}
		printf("%.5f\n", ans);
	}
	return 0;
}
