#include <cstdio>
#include <algorithm>
#include <functional>
#include <vector>

using namespace std;

const int INF = 1e9;
pair<int, long long> dp[50001];
vector<pair<int, long long> > vp[50001];
long long ans[50000];

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i <= n; ++i)
	{
		dp[i] = make_pair(INF, 0);
		vp[i].push_back(make_pair(0, 0));
	}
	for (int i = 0; i < n; ++i)
	{
		int t;
		scanf("%d", &t);
		t = -t;
		int p = lower_bound(dp, dp + n, make_pair(t, -1ll)) - dp;
		if (dp[p].first != t)
		{
			if (p == 0)
			{
				vp[p].push_back(make_pair(-t, vp[p].back().second + 1));
				ans[p]++;
			}
			else
			{
				long long cnt = vp[p - 1].back().second - (--lower_bound(vp[p - 1].begin(), vp[p - 1].end(), make_pair(-t + 1, -1ll)))->second;
				vp[p].push_back(make_pair(-t, vp[p].back().second + cnt));
				ans[p] += cnt;
			}
			dp[p] = make_pair(t, i);
		}
	}
	for (int i = 0; i < n; ++i)
	{
		if (dp[i + 1].first == INF)
		{
			printf("%d %lld\n", i + 1, ans[i]);
			break;
		}
	}
	return 0;
}

