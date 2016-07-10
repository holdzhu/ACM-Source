#include <cstdio>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int, int> > v;
int a[200000];
int ans[200000];

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; ++i)
		scanf("%d", &a[i]);
	for (int i = 0; i < m; ++i)
	{
		int t, r;
		scanf("%d %d", &t, &r);
		while (v.size() && v.back().second <= r)
			v.pop_back();
		v.push_back({t, r});
	}
	v.push_back({1, 0});
	for (int i = n - 1; i >= v[0].second; --i)
		ans[i] = a[i];
	multiset<int> s;
	for (int i = 0; i < v[0].second; ++i)
		s.insert(a[i]);
	int t = v[0].first;
	for (int i = v[0].second - 1, j = 0; i >= 0; --i)
	{
		while (j < v.size() && v[j].second > i)
			t = v[j++].first;
		if (t == 1)
		{
			ans[i] = *--s.end();
			s.erase(--s.end());
		}
		else
		{
			ans[i] = *s.begin();
			s.erase(s.begin());
		}
	}
	for (int i = 0; i < n; ++i)
		printf("%d ", ans[i]);
	return 0;
}
