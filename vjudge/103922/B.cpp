#include <cstdio>
#include <queue>
#include <algorithm>

using namespace std;

pair<pair<int, int>, int> p[50000];

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d %d %d", &p[i].first.first, &p[i].first.second, &p[i].second);
	}
	sort(p, p + n);
	int cnt = 0;
	priority_queue<pair<int, int> > pq;
	for (int i = 0, j = 0; i <= 50005; ++i)
	{
		while (j < n && p[j].first.first == i)
		{
			pq.push(make_pair(cnt + p[j].second - p[j].first.second, p[j].first.second));
			j++;
		}
		if (pq.size() && -pq.top().first < i - cnt)
		{
			cnt++;
		}
		while (pq.size() && pq.top().second <= i)
		{
			pq.pop();
		}
	}
	printf("%d\n", cnt);
	return 0;
}
