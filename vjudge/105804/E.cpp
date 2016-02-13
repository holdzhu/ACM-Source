#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int k[10000], l[10000];
int c[10000];
int cnt[10000];

int main()
{
	freopen("changes.in", "r", stdin);
	freopen("changes.out", "w", stdout);
	int m;
	scanf("%d", &m);
	int sum1 = 0, sum2 = 0;
	for (int i = 0; i < m; ++i)
		scanf("%d", &k[i]), sum1 += k[i];
	for (int i = 0; i < m; ++i)
		scanf("%d", &l[i]), sum2 += l[i];
	bool flag = true;
	for (int i = 1; i < m; ++i)
	{
		int t = (l[i] - k[i]) - (l[0] - k[0]);
		if (t % m != 0)
		{
			flag = false;
			break;
		}
		c[i] = t / m;
		c[0] = max(c[0], -c[i]);
	}
	if (!flag || sum1 != sum2)
	{
		puts("-1");
		return 0;
	}
	int ans = c[0];
	for (int i = 1; i < m; ++i)
		c[i] += c[0], ans += c[i];
	priority_queue<pair<int, int> > pq;
	for (int i = 0; i < m; ++i)
		pq.push({-k[i], i});
	int cur = 0;
	copy(c, c + m, cnt);
	vector<int> lst;
	while (!pq.empty())
	{
		int u = -pq.top().first;
		int v = pq.top().second;
		pq.pop();
		if (u - cur < 0)
		{
			flag = false;
			break;
		}
		if (c[v])
		{
			c[v]--;
			cur++;
			lst.push_back(v + 1);
			pq.push({-(u + m), v});
		}
		else if (u - ans < 0)
		{
			flag = false;
			break;
		}
	}
	if (flag)
	{
		printf("%d\n", ans);
		for (int i = 0; i < ans; ++i)
			printf("%d ", lst[i]);
		puts("");
	}
	else
		puts("-1");
	return 0;
}
