#include <cstdio>
#include <vector>

using namespace std;

int p[100001];
int cnt[100001];

int findset(int x)
{
	return x == p[x] ? x : p[x] = findset(p[x]);
}

int n, m;
int c[100001];
int dp[100001];

void update(int y, int x)
{
	for (int i = n; i >= y; --i)
		dp[i] = min(dp[i], dp[i - y] + x);
}

bool check(int x)
{
	while (x)
	{
		int m = x % 10;
		x /= 10;
		if (m != 4 && m != 7)
			return false;
	}
	return true;
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; ++i)
		p[i] = i;
	for (int i = 1; i <= m; ++i)
	{
		int u, v;
		scanf("%d %d", &u, &v);
		int x = findset(u);
		int y = findset(v);
		p[x] = y;
	}
	for (int i = 1; i <= n; ++i)
		cnt[findset(i)]++;
	for (int i = 1; i <= n; ++i)
		c[cnt[i]]++;
	for (int i = 1; i <= n; ++i)
		dp[i] = 1e9;
	for (int i = 1; i <= n; ++i)
		if (c[i])
		{
			for (int z = 1; z < c[i]; z <<= 1)
				update(z * i, z), c[i] -= z;
			update(c[i] * i, c[i]);
		}
	int ans = 1e9;
	for (int i = 1; i <= n; ++i)
		if (check(i))
			ans = min(ans, dp[i]);
	printf("%d\n", ans < 1e9 ? ans - 1 : -1);
	return 0;
}
