#include <cstdio>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

map<int, int> ma;

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	while (n--)
	{
		int t;
		scanf("%d", &t);
		ma[t] = n;
	}
	vector<pair<int, int> > ans;
	for (auto p: ma)
		ans.push_back({p.second, p.first});
	sort(ans.begin(), ans.end());
	for (int i = 0; i < ans.size() && i < m; ++i)
		printf("%d\n", ans[i].second);
	return 0;
}
