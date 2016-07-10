#include <cstdio>
#include <map>

using namespace std;

int x[2000], y[2000];

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d %d", &x[i], &y[i]);
	map<pair<int, int>, int> mp;
	for (int i = 0; i < n; ++i)
		for (int j = i + 1; j < n; ++j)
			mp[{x[i] + x[j], y[i] + y[j]}]++;
	int ans = 0;
	for (auto &p : mp)
		ans += p.second * (p.second - 1) / 2;
	printf("%d\n", ans);
	return 0;
}
