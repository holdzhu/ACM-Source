#include <cstdio>
#include <map>
#include <algorithm>

using namespace std;

pair<int, int> a[1000];
int x[1000];
int dp[1000][1000];


int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int n;
		scanf("%d", &n);
		map<int, int> id;
		for (int i = 0; i < n; ++i)
		{
			scanf("%d %d", &a[i].first, &a[i].second);
			a[i].first = -a[i].first;
			id[a[i].second] = 0;
		}
		sort(a, a + n);
		int N = 0;
		for (map<int, int>::iterator it = id.begin(); it != id.end(); ++it)
		{
			it->second = N++;
		}
		for (int i = 0; i < n; ++i)
		{
			x[i] = id[a[i].second];
		}
	}
	return 0;
}
