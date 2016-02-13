#include <cstdio>
#include <vector>
#include <cassert>
#include <algorithm>
#include <set>

using namespace std;

const long double eps = 1e-12;
const int maxn = 2e4;

vector<pair<long double, pair<int, int> > > p;
int x[maxn], r[maxn], g[maxn], d[maxn];

int main()
{
	int n, s, vmin, vmax;
	scanf("%d %d %d %d", &n, &s, &vmin, &vmax);
	p.push_back(make_pair(vmin - eps, make_pair(-1, -1)));
	p.push_back(make_pair(vmax + eps, make_pair(1, -1)));
	for (int i = 0; i < n; ++i)
	{
		scanf("%d %d %d %d", &x[i], &r[i], &g[i], &d[i]);
		long double a = 1.0l * d[i] / x[i];
		long double b = 1.0l * (d[i] + r[i]) / x[i];
		long double c = 1.0l * (g[i] + r[i]) / x[i];
		for (int k = d[i] > g[i] ? -1 : 0; (a + k * c <= 0 ? 100 : 1 / (a + k * c)) > vmin - eps; ++k)
		{
			p.push_back(make_pair(1 / (b + k * c) + eps, make_pair(1, i)));
			p.push_back(make_pair((a + k * c <= 0 ? 100 : 1 / (a + k * c)) - eps, make_pair(-1, i)));
		}
	}
	int cnt = 1;
	sort(p.begin(), p.end());
	long double ansv = 0;
	int ansc = 1e9;
	bool flag = false;
	for (int i = 0; i < p.size(); ++i)
	{
		if (flag && ansc >= cnt)
		{
			ansc = cnt;
			ansv = p[i].first - eps;
		}
		if (p[i].second.second == -1)
			flag = p[i].second.first == -1;
		cnt += p[i].second.first;
	}
	printf("%.10f\n", (double)ansv);
	printf("%d\n", ansc);
	vector<int> ans;
	for (int i = 0; i < n; ++i)
	{
		long double a = 1.0l * d[i] / x[i];
		long double b = 1.0l * (d[i] + r[i]) / x[i];
		long double c = 1.0l * (g[i] + r[i]) / x[i];
		for (int k = d[i] > g[i] ? -1 : 0; (a + k * c <= 0 ? 100 : 1 / (a + k * c)) > vmin - eps; ++k)
		{
			if (1 / (b + k * c) + eps < ansv && ansv < (a + k * c <= 0 ? 100 : 1 / (a + k * c)) - eps)
			{
				ans.push_back(i + 1);
				break;
			}
		}
	}
	assert(ansc == ans.size());
	for (int i = 0; i < ans.size(); ++i)
	{
		printf("%d%s", ans[i], i == ans.size() - 1 ? "\n" : " ");
	}
	return 0;
}
