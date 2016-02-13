#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
	// freopen("trees.in", "r", stdin);
	// freopen("trees.out", "w", stdout);
	int n, k;
	scanf("%d %d", &n, &k);
	int first;
	scanf("%d", &first);
	int last = first;
	int gcd = 0;
	while (--k)
	{
		scanf("%d", &last);
		gcd = __gcd(gcd, last - first);
	}
	long long ans = 0;
	if (gcd == 0)
	{
		vector<pair<int, pair<int, int> > > v;
		for (int i = 1; i * i <= first - 1; ++i)
		{
			v.push_back(make_pair(i, make_pair(1, (first - 1) / i)));
			v.push_back(make_pair((first - 1) / (i + 1) + 1, make_pair(1, i)));
		}
		v.push_back(make_pair(first - 1 + 1, make_pair(1, 0)));
		for (int i = 1; i * i <= n - last; ++i)
		{
			v.push_back(make_pair(i, make_pair(2, (n - last) / i)));
			v.push_back(make_pair((n - last) / (i + 1) + 1, make_pair(2, i)));
		}
		v.push_back(make_pair(n - last + 1, make_pair(2, 0)));
		v.push_back(make_pair(1, make_pair(0, 0)));
		sort(v.begin(), v.end());
		int a = 0, b = 0;
		for (int i = 1; i < v.size(); ++i)
		{
			ans += (1ll * (a + 1) * (b + 1) - 1) * (v[i].first - v[i - 1].first);
			if (v[i].second.first == 1)
				a = v[i].second.second;
			else
				b = v[i].second.second;
		}
	}
	else
		for (int i = 1; i * i <= gcd; ++i)
		{
			if (gcd % i == 0)
			{
				ans += 1ll * ((first - 1) / i + 1) * ((n - last) / i + 1);
				if (i * i < gcd)
					ans += 1ll * ((first - 1) / (gcd / i) + 1) * ((n - last) / (gcd / i) + 1);
			}
		}
	printf("%I64d\n", ans + (gcd == 0));
	return 0;
}
