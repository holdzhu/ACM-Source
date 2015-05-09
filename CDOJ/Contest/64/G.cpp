#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int c;
int t;
double p[101];
int n[100];
int sn[101];

int main()
{
	int Journey = 1;
	while (scanf("%d %d", &c, &t) == 2 && c && t)
	{
		double ans = 0;
		sn[0] = 0;
		for (int i = 0; i < t; ++i)
		{
			scanf("%lf %d", &p[i], &n[i]);
			sn[i + 1] = sn[i] + n[i];
		}
		p[t] = 0;
		for (int i = 0; i < t; ++i)
		{
			if (p[i] > p[i + 1])
			{
				ans += (p[i] - p[i + 1]) * sn[i + 1];
			}
			else
			{
				ans += (p[i] - p[i + 1]) * (sn[i] + c);
			}
		}
		printf("Journey %d: %.2f\n", Journey++, ans);
	}
	return 0;
}
