#include <cstdio>
#include <cstring>
#include <algorithm>
#include <deque>

using namespace std;

struct Flower
{
	long long a, b, t;
	bool operator < (const Flower& rhs) const
	{
		return t < rhs.t || (t == rhs.t && a < rhs.a) || (t == rhs.t && a == rhs.a && b < rhs.b);
	}
};

struct Node
{
	int pos;
	long long val;
};

long long dp[2][100000];
Flower flower[100];

int main()
{
	int n, m, d;
	scanf("%d %d %d", &n, &m, &d);
	for (int i = 0; i < m; ++i)
	{
		scanf("%lld %lld %lld", &flower[i].a, &flower[i].b, &flower[i].t);
		flower[i].a--;
	}
	sort(flower, flower + m);
	memset(dp, 0, sizeof dp);
	bool cur = 0;
	long long lastTime = 1;
	for (int i = 0; i < m; ++i)
	{
		int step = ((flower[i].t - lastTime) * d > n) ? n : ((flower[i].t - lastTime) * d);
		deque<Node> q;
		int left = 0;
		int right = -1;
		cur = !cur;
		for (int j = 0; j < n; ++j)
		{
			int newLeft = max(0, j - step);
			int newRight = min(n - 1, j + step);
			while (!q.empty() && q.back().pos < newLeft)
			{
				q.pop_back();
			}
			for (int k = right + 1; k <= newRight; ++k)
			{
				while (!q.empty() && q.front().val <= dp[!cur][k])
				{
					q.pop_front();
				}
				q.push_front((Node){k, dp[!cur][k]});
			}
			left = newLeft;
			right = newRight;
			dp[cur][j] = q.back().val + flower[i].b - abs(j - flower[i].a);
		}
		lastTime = flower[i].t;
	}
	long long ans = -10000000000000;
	for (int i = 0; i < n; ++i)
	{
		ans = max(ans, dp[cur][i]);
	}
	printf("%lld\n", ans);
	return 0;
}
