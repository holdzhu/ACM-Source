#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

double p[400];
double dp[2][401];

int main()
{
	int T;
	scanf("%d", &T);
	for (int kase = 1; kase <= T; ++kase)
	{
		int N, K;
		scanf("%d %d", &N, &K);
		for (int i = 0; i < N; ++i)
			scanf("%lf", &p[i]);
		sort(p, p + N);
		printf("Case #%d: ", kase);
		double ans = 0;
		for (int i = 0; i < N; ++i)
		{
			auto &x = dp[0], &y = dp[1];
			memset(y, 0, sizeof y);
			y[0] = 1;
			for (int j = 0; j < K; ++j)
			{
				swap(x, y);
				memset(y, 0, sizeof y);
				for (int k = 0; k <= j; ++k)
				{
					y[k] += x[k] * p[(i + j) % N];
					y[k + 1] += x[k] * (1 - p[(i + j) % N]);
				}
			}
			ans = max(ans, y[K / 2]);
		}
		printf("%.10f\n", ans);
	}
	return 0;
}
