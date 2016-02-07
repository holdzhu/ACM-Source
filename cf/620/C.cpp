#include <cstdio>
#include <set>
#include <vector>

using namespace std;

int main()
{
	int n;
	scanf("%d", &n);
	vector<pair<int, int> > ans;
	set<int> s;
	int last = 0;
	for (int i = 0; i < n; ++i)
	{
		int t;
		scanf("%d", &t);
		if (s.count(t))
		{
			ans.push_back(make_pair(last, i));
			last = i + 1;
			s.clear();
		}
		else
			s.insert(t);
	}
	if (ans.empty())
		puts("-1");
	else
	{
		ans.back().second = n - 1;
		printf("%d\n", ans.size());
		for (int i = 0; i < ans.size(); ++i)
			printf("%d %d\n", ans[i].first + 1, ans[i].second + 1);
	}
	return 0;
}
