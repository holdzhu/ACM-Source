#include <cstdio>
#include <cmath>

int main()
{
	int n;
	double d;
	scanf("%d %lf", &n, &d);
	int t;
	while (scanf("%d", &t) == 1)
	{
		int h = 0, m = 0, s = 0;
		bool flag = true;
		for (int i = 0; i < n; ++i)
		{
			int times[3] = {0, 0, 0};
			char ss[100];
			scanf("%s", ss);
			int p = 0;
			for (int i = 0; ss[i] != '\0'; ++i)
			{
				if (ss[i] == '-')
				{
					flag = false;
					break;
				}
				if (ss[i] == ':')
				{
					p++;
				}
				else
				{
					times[p] *= 10;
					times[p] += ss[i] - '0';
				}
			}
			h += times[0];
			m += times[1];
			s += times[2];
		}
		printf("%3d: ", t);
		if (flag)
		{
			double t = (h * 3600 + m * 60 + s) / d;
			int ans = (int)round(t);
			printf("%d:%02d min/km\n", ans / 60, ans % 60);
		}
		else
		{
			printf("-\n");
		}
	}
	return 0;
}
