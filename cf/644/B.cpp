#include <cstdio>
#include <queue>
#include <algorithm>

using namespace std;

long long ans[200000];

int main()
{
	int n, b;
	scanf("%d %d", &n, &b);
	queue<pair<int, int> > q;
	long long lasttime = 0;
	for (int i = 0; i < n; ++i)
	{
		int t, d;
		scanf("%d %d", &t, &d);
		while (q.size() && lasttime <= t)
		{
			int u = q.front().first;
			int v = q.front().second;
			q.pop();
			ans[u] = lasttime += v;
		}
		if (q.empty() && lasttime <= t)
			ans[i] = lasttime = t + d;
		else if (q.size() < b)
			q.push({i, d});
		else
			ans[i] = -1;
	}
	while (q.size())
	{
		int u = q.front().first;
		int v = q.front().second;
		q.pop();
		ans[u] = lasttime += v;
	}
	for (int i = 0; i < n; ++i)
		printf("%I64d ", ans[i]);
	puts("");
	return 0;
}
