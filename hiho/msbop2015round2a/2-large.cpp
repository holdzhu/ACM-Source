#include <cstdio>
#include <algorithm>

using namespace std;

struct Pyramid
{
	int x, y, w;
	bool operator < (const Pyramid& rhs) const
	{
		return x - y < rhs.x - rhs.y || (x - y == rhs.x - rhs.y && x + y > rhs.x + rhs.y);
	}
};

Pyramid a[1000];
double dp[1000];
double ans;
int N;

int main()
{
	int T;
	scanf("%d", &T);
	for (int kase = 0; kase < T; ++kase)
	{
		scanf("%d", &N);
		for (int i = 0; i < N; ++i)
		{
			scanf("%d %d %d", &a[i].x, &a[i].y, &a[i].w);
		}
		sort(a, a + N);
		ans = 0;
		for (int i = 0; i < N; ++i)
		{
			double t = 0;
			for (int j = i + 1; j < N; ++j)
			{
				if (a[i].x - a[i].y <= a[j].x - a[j].y && a[i].x + a[i].y >= a[j].x + a[j].y)
				{
					t += a[j].w;
				}
			}
			dp[i] = a[i].w - a[i].y * a[i].y;
			for (int j = 0; j < i; ++j)
			{
				if (a[i].x - a[i].y >= a[j].x - a[j].y && a[i].x + a[i].y <= a[j].x + a[j].y)
				{
					continue;
				}
				if (a[i].x - a[i].y > a[j].x + a[j].y)
				{
					dp[i] = max(dp[i], dp[j] + a[i].w - a[i].y * a[i].y);
				}
				else if (a[i].x + a[i].y > a[j].x + a[j].y)
				{
					dp[i] = max(dp[i], dp[j] + a[i].w - a[i].y * a[i].y + 0.25 * (a[j].x + a[j].y - a[i].x + a[i].y) * (a[j].x + a[j].y - a[i].x + a[i].y));
				}
				else
				{
					dp[i] = max(dp[i], dp[j] + a[i].w);
				}
			}
			dp[i] += t;
			ans = max(ans, dp[i]);
		}
		printf("Case #%d: %.2f\n", kase + 1, ans);
	}
	return 0;
}
