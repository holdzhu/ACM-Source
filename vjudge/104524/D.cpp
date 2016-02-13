#include <cstdio>
#include <algorithm>

using namespace std;

int n, k;
int x[1000], y[1000];
int dis[1000][1000];
int cnt[1000];
int vis[1000];
int far[1000][1000];
int farc[1000];
int zero;

bool check(int i, int K, int mx)
{
	if (K > k || zero < n - k)
		return false;
	if (i == n)
		return true;
	vis[i] = 1;
	if (cnt[i] == 0)
	{
		int tzero = zero;
		for (int j = 0; j < farc[i]; ++j)
		{
			if (cnt[far[i][j]] == 0)
				zero--;
			cnt[far[i][j]]++;
		}
		if (check(i + 1, K, mx))
			return true;
		for (int j = 0; j < farc[i]; ++j)
			cnt[far[i][j]]--;
		zero = tzero;
	}
	vis[i] = 0;
	if (check(i + 1, K + 1, mx))
		return true;
	return false;
}

int main()
{
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; ++i)
		scanf("%d %d", &x[i], &y[i]);
	for (int i = 0; i < n; ++i)
		for (int j = i + 1; j < n; ++j)
			dis[i][j] = dis[j][i] = (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]);
	int l = 0;
	int r = 32000 * 32000 * 2 + 100;
	while (l < r)
	{
		int m = (0ll + l + r) >> 1;
		bool flag = false;
		for (int i = 0; i < n; ++i)
		{
			farc[i] = 0;
			for (int j = 0; j < n; ++j)
				if (dis[i][j] > m)
					far[i][farc[i]++] = j;
			if (farc[i] <= k)
				flag = true;
		}
		if (!flag)
		{
			l = m + 1;
			continue;
		}
		for (int i = 0; i < n; ++i)
			cnt[i] = vis[i] = 0;
		zero = n;
		if (check(0, 0, m))
			r = m;
		else
			l = m + 1;
	}
	int m = l;
	for (int i = 0; i < n; ++i)
	{
		farc[i] = 0;
		for (int j = 0; j < n; ++j)
			if (dis[i][j] > m)
				far[i][farc[i]++] = j;
	}
	for (int i = 0; i < n; ++i)
		cnt[i] = vis[i] = 0;
	zero = n;
	check(0, 0, m);
	for (int i = 0; i < n; ++i)
		if (!vis[i])
			printf("%d ", i + 1), k--;
	for (int i = 0; i < n && k > 0; ++i)
		if (vis[i])
			printf("%d ", i + 1), k--;
		puts("");
	return 0;
}
