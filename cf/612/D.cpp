#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

pair<int, int> p[1000000];
vector<pair<int, int> > ans;

int main()
{
	int n, k;
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d %d", &p[i].first, &p[i].second);
	}
	sort(p, p + n);
	priority_queue<int> pq;
	int cnt = 0;
	for (int i = 0; i < n; ++i)
	{
		while (pq.size() && -pq.top() < p[i].first)
		{
			if (cnt == k)
			{
				ans.back().second = -pq.top();
			}
			pq.pop();
			cnt--;
		}
		pq.push(-p[i].second);
		cnt++;
		if (cnt == k)
		{
			ans.push_back(make_pair(p[i].first, p[i].first));
		}
	}
	while (pq.size())
	{
		if (cnt == k)
		{
			ans.back().second = -pq.top();
		}
		pq.pop();
		cnt--;
	}
	printf("%u\n", ans.size());
	for (int i = 0; i < ans.size(); ++i)
	{
		printf("%d %d\n", ans[i].first, ans[i].second);
	}
	return 0;
}
