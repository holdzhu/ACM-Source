#include <cstdio>

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int n;
		scanf("%d", &n);
		double p[n + 1];
		double o[n];
		p[0] = 0;
		double s = 0;
		for (int i = 0; i < n; ++i)
		{
			scanf("%lf", &o[i]);
			if (o[i] > 0.5)
			{
				s += 2;
			}
			else
			{
				s += o[i] / (1 - o[i]);
			}
			p[i + 1] = s;
		}
		int m;
		scanf("%d", &m);
		while (m--)
		{
			int L, R;
			scanf("%d %d", &L, &R);
			if (p[R + 1] - p[L] == 1)
			{
				if (L != 0)
				{
					printf("0\n");
				}
				else
				{
					printf("%d\n", R + 1);
				}
			}
			else if (p[R + 1] - p[L] > 1)
			{
				int minx;
				if (L != 0)
				{
					minx = 0;
				}
				else
				{
					minx = R + 1;
				}
				for (int i = 0; i < L; ++i)
				{
					if (o[i] < o[minx])
					{
						minx = i;
					}
				}
				for (int i = R + 1; i < n; ++i)
				{
					if (o[i] < o[minx])
					{
						minx = i;
					}
				}
				printf("%d\n", minx);
			}
			else
			{
				int maxx;
				if (L != 0)
				{
					maxx = 0;
				}
				else
				{
					maxx = R + 1;
				}
				for (int i = 0; i < L; ++i)
				{
					if (o[i] > o[maxx])
					{
						maxx = i;
					}
				}
				for (int i = R + 1; i < n; ++i)
				{
					if (o[i] > o[maxx])
					{
						maxx = i;
					}
				}
				printf("%d\n", maxx);
			}
		}
	}
	return 0;
}
