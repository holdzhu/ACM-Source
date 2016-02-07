#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 1e5 + 10;

pair<int, int> p[maxn];
int premi[maxn];
int premx[maxn];
int sufmi[maxn];
int sufmx[maxn];

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d %d", &p[i].first, &p[i].second);
	sort(p, p + n);
	long long ans = 1e18;
	for (int it = 0; it < 2; ++it)
	{
		premi[0] = sufmi[n] = 1e9;
		premx[0] = sufmx[n] = -1e9;
		for (int i = 0; i < n; ++i)
		{
			premi[i + 1] = min(premi[i], p[i].second);
			premx[i + 1] = max(premx[i], p[i].second);
		}
		for (int i = n - 1; i >= 0; --i)
		{
			sufmi[i] = min(sufmi[i + 1], p[i].second);
			sufmx[i] = max(sufmx[i + 1], p[i].second);
		}
		ans	= min(ans, 1ll * (premx[n] - premi[n]) * (premx[n] - premi[n]));
		int st = -1;
		for (; st < n - 1 && p[st + 1].first <= 0; ++st)
			;
		long long L = 0;
		long long R = 1e18;
		while (L < R)
		{
			long long M = (L + R) >> 1;
			bool flag = false;
			for (int i = st, j = st; i >= 0; --i)
			{
				while (1ll * (p[j].first - p[i].first)
						   * (p[j].first - p[i].first)
					   > M)
					--j;
				while (j < n - 1
					   && 1ll * (p[j + 1].first - p[i].first)
								  * (p[j + 1].first - p[i].first)
							  <= M
					   && p[j + 1].first <= -p[i].first)
					++j;
				int mi = min(premi[i], sufmi[j + 1]);
				int mx = max(premx[i], sufmx[j + 1]);
				if ((mi > 0
					 || 1ll * p[i].first * p[i].first + 1ll * mi * mi <= M)
					&& (mx < 0
						|| 1ll * p[i].first * p[i].first + 1ll * mx * mx <= M)
					&& (mi > 0 || mx < 0 || 1ll * (mx - mi) * (mx - mi) <= M))
				{
					flag = true;
					break;
				}
			}
			if (flag)
				R = M;
			else
				L = M + 1;
		}
		ans = min(ans, L);
		reverse(p, p + n);
		for (int i = 0; i < n; ++i)
			p[i].first = -p[i].first;
	}
	printf("%I64d\n", ans);
	return 0;
}
