#include <cstdio>
#include <map>
#include <vector>
#include <set>

using namespace std;

map<vector<int>, int> dp[2];
unsigned pw[101];

int findset(vector<int> &p, int x)
{
	return x == p[x] ? x : p[x] = findset(p, p[x]);
}

void unionset(vector<int> &p, int u, int v)
{
	u = findset(p, u);
	v = findset(p, v);
	if (u < v)
		p[v] = u;
	else
		p[u] = v;
}

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	pw[0] = 1;
	for (int i = 1; i <= n; ++i)
		pw[i] = pw[i - 1] * m;
	dp[0][vector<int>()] = 1;
	auto &y = dp[0], &x = dp[1];
	unsigned ans = m;
	for (int i = 1; i <= n / 2; ++i)
	{
		swap(x, y);
		y.clear();
		for (pair<vector<int>, int> pr : x)
		{
			pr.first.push_back(i * 2 - 2);
			pr.first.push_back(i * 2 - 1);
			y[pr.first] += pr.second;
			for (int j = 0; j < i; ++j)
				unionset(pr.first, j, j + i);
			for (int j = 0; j < i * 2; ++j)
				findset(pr.first, j);
			pr.second = -pr.second;
			y[pr.first] += pr.second;
		}
		unsigned tmp = 0;
		for (pair<vector<int>, int> pr : y)
		{
			set<int> s;
			for (int v: pr.first)
				s.insert(v);
			tmp += pr.second * pw[s.size()];
		}
		if (i * 2 < n)
			tmp *= 1 + m;
		ans += tmp;
	}
	printf("%u\n", ans);
	return 0;
}
