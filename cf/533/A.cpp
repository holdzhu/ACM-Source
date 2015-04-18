#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int n, k;
int h[500000];
int m[500000];
int p[500000];
int parent[500000];
int s[500000];
vector<int> G[500000];

void dfs(int x, int pa, int v)
{
	parent[x] = pa;
	m[x] = v;
	for (int i = 0; i < G[x].size(); ++i)
	{
		if (pa != G[x][i])
		{
			dfs(G[x][i], x, min(v, h[G[x][i]]));
		}
	}
}

bool cmp(const int& a, const int& b)
{
	return m[a] < m[b];
}

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &h[i]);
		p[i] = i;
	}
	for (int i = 0; i < n - 1; ++i)
	{
		int l, r;
		scanf("%d %d", &l, &r);
		l--;
		r--;
		G[l].push_back(r);
		G[r].push_back(l);
	}
	dfs(0, -1, h[0]);
	sort(p, p + n, cmp);
	scanf("%d", &k);
	for (int i = 0; i < k; ++i)
	{
		scanf("%d", &s[i]);
	}
	sort(s, s + k);
	set<int> se;
	int mx = 0;
	for (int i = n; i >= n - k; --i)
	{
		if (m[p[i]] < s[i - n + k])
		{
			se.insert(i);
			mx = max(mx, s[i - n + k] - m[p[i]]);
		}
	}
	if (se.empty())
	{
		printf("0\n");
	}
	else
	{
		set<int> cause;
		for (set<int>::iterator i = se.begin(); i != se.end(); ++i)
		{
			int u = p[*i];
			while (u >= 0)
			{
				if (h[u] == m[p[*i]])
				{
					cause.insert(u);
				}
				u = parent[u];
			}
			if (cause.size() > 1)
			{
				break;
			}
		}
		if (cause.size() > 1)
		{
			printf("-1\n");
		}
		else
		{
			printf("%d\n", mx);
		}
	}
	return 0;
}
