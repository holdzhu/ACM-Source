#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

pair<int, int> a[200001];
pair<int, int> b[200001];
vector<pair<long long, int> > c1, c2;

int main()
{
	int n, m, k, s;
	scanf("%d %d %d %d", &n, &m, &k, &s);
	a[0].first = 1e9;
	for (int i = 1; i <= n; ++i)
	{
		scanf("%d", &a[i].first);
		a[i].second = i;
		a[i] = min(a[i], a[i - 1]);
	}
	b[0].first = 1e9;
	for (int i = 1; i <= n; ++i)
	{
		scanf("%d", &b[i].first);
		b[i].second = i;
		b[i] = min(b[i], b[i - 1]);
	}
	c1.push_back(make_pair(0, -1));
	c2.push_back(make_pair(0, -1));
	for (int i = 1; i <= m; ++i)
	{
		int t, c;
		scanf("%d %d", &t, &c);
		if (t == 1)
			c1.push_back(make_pair(c, i));
		else
			c2.push_back(make_pair(c, i));
	}
	sort(c1.begin(), c1.end());
	sort(c2.begin(), c2.end());
	for (int i = 1; i < c1.size(); ++i)
		c1[i].first += c1[i - 1].first;
	for (int i = 1; i < c2.size(); ++i)
		c2[i].first += c2[i - 1].first;
	int L = 1;
	int R = n + 1;
	while (L < R)
	{
		int M = (L + R) >> 1;
		long long mi = 1e18;
		for (int i = min(k, (int)c1.size() - 1); i >= 0 && k - i <= c2.size() - 1; --i)
			mi = min(mi, 1ll * c1[i].first * a[M].first + 1ll * c2[k - i].first * b[M].first);
		if (mi <= s)
			R = M;
		else
			L = M + 1;
	}
	if (R == n + 1)
		puts("-1");
	else
	{
		printf("%d\n", L);
		long long mi = 1e18;
		for (int i = min(k, (int)c1.size() - 1); i >= 0 && k - i <= c2.size() - 1; --i)
			mi = min(mi, 1ll * c1[i].first * a[L].first + 1ll * c2[k - i].first * b[L].first);
		for (int i = min(k, (int)c1.size() - 1); i >= 0 && k - i <= c2.size() - 1; --i)
			if (1ll * c1[i].first * a[L].first + 1ll * c2[k - i].first * b[L].first == mi)
			{
				for (int j = 1; j <= i; ++j)
					printf("%d %d\n", c1[j].second, a[L].second);
				for (int j = 1; j <= k - i; ++j)
					printf("%d %d\n", c2[j].second, b[L].second);
				break;
			}
	}
	return 0;
}
