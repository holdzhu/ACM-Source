#include <cstdio>
#include <cmath>

long long t[10010];
long long wx[10010];
long long wy[10010];

int main()
{
	freopen("joy.in", "r", stdin);
	freopen("joy.out", "w", stdout);
	long long sx, sy, fx, fy;
	scanf("%I64d %I64d %I64d %I64d", &sx, &sy, &fx, &fy);
	long long n, k, vmax;
	scanf("%I64d %I64d %I64d", &n, &k, &vmax);
	long long lx = 0;
	long long ly = 0;
	long long sumx = 0, sumy = 0;
	long long lt = 0;
	for (int i = 0; i < n; ++i)
	{
		scanf("%I64d %I64d %I64d", &t[i], &wx[i], &wy[i]);
		sumx += (t[i] - lt) * lx;
		sumy += (t[i] - lt) * ly;
		lx = wx[i];
		ly = wy[i];
		lt = t[i];
	}
	sumx += (k - lt) * lx;
	sumy += (k - lt) * ly;
	long long sqrdis = (sx + sumx - fx) * (sx + sumx - fx) + (sy + sumy - fy) * (sy + sumy - fy);
	long long sqrmxdis = vmax * vmax * k * k;
	if (sqrdis <= sqrmxdis)
	{
		puts("Yes");
		double vx = 1.0 * (fx - sx - sumx) / k;
		double vy = 1.0 * (fy - sy - sumy) / k;
		double posx = sx;
		double posy = sy;
		double nwx = 0;
		double nwy = 0;
		for (int i = 0, j = 0; i < k; ++i)
		{
			if (j < n && t[j] == i)
			{
				nwx = wx[j];
				nwy = wy[j];
				j++;
			}
			posx += nwx;
			posy += nwy;
			posx += vx;
			posy += vy;
			printf("%.10f %.10f\n", posx, posy);
		}
	}
	else
	{
		puts("No");
	}
	return 0;
}
