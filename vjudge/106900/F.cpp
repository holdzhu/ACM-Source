#include <cstdio>
#include <algorithm>

using namespace std;

int r[1000];
int dp1[1000][1001];
int dp2[1001][1001];
int dp3[1001][51];
pair<int, int> rev[1001];

int main()
{
	freopen("flight.in", "r", stdin);
	freopen("flight.out", "w", stdout);
	int n, s, k;
	scanf("%d %d %d", &n, &s, &k);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &r[i]);
		rev[i] = {r[i], i};
	}
	sort(rev, rev + n);
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < i; ++j)
			dp1[i][r[j]]++;
		for (int j = 1; j <= s; ++j)
			dp1[i][j] += dp1[i][j - 1];
	}
	for (int i = 1; i <= s; ++i)
	{
		int p = 0;
		while (rev[p].first < i)
			++p;
		for (int j = i; j <= s; ++j)
		{
			dp2[i][j] = dp2[i][j - 1];
			while (p < n && rev[p].first <= j)
			{
				dp2[i][j] += dp1[rev[p].second][j - 1] - dp1[rev[p].second][i - 1];
				++p;
			}
		}
	}
	for (int i = 1; i <= s; ++i)
	{
		dp3[i][0] = 1e9;
		for (int j = 0; j < k; ++j)
		{
			dp3[i][j + 1] = 1e9;
			for (int l = 1; l <= i; ++l)
				dp3[i][j + 1] = min(dp3[i][j + 1], dp3[l - 1][j] + dp2[l][i]);
		}
	}
	printf("%d\n", dp3[s][k]);
	return 0;
}
