#include <cstdio>
#include <vector>
#include <map>

using namespace std;

int n;
map<pair<int, int>, int> id;
vector<int> G[6000];
pair<int, int> pos[6000];
int height[6000];
tuple<int, int, int> tri[2000];

int readPoint()
{
	int x, y, z;
	scanf("%d %d %d", &x, &y, &z);
	auto it = id.find({x, y});
	if (it != id.end())
		return it->second;
	int i = id.size();
	id[{x, y}] = i;
	pos[i] = {x, y};
	height[i] = z;
	return i;
}

int findTri(int x, int y)
{
	for (int t = 0; t < n; ++t)
	{
		int i, j, k;
		tie(i, j, k) = tri[t];
		int xi = pos[i].first;
		int yi = pos[i].second;
		int xj = pos[j].first;
		int yj = pos[j].second;
		int xk = pos[k].first;
		int yk = pos[k].second;
		long long c1 = 1ll * (xj - xi) * (yi - y) - 1ll * (yj - yi) * (xi - x);
		long long c2 = 1ll * (xk - xj) * (yj - y) - 1ll * (yk - yj) * (xj - x);
		long long c3 = 1ll * (xi - xk) * (yk - y) - 1ll * (yi - yk) * (xk - x);
		if (c1 <= 0 && c2 <= 0 && c3 <= 0)
			return t;
	}
	return -1;
}

void init()
{
	for (int t = 0; t < n; ++t)
	{
		int i, j, k;
		tie(i, j, k) = tri[t];
		int xi = pos[i].first;	
		int yi = pos[i].second;
		int xj = pos[j].first;
		int yj = pos[j].second;
		int xk = pos[k].first;
		int yk = pos[k].second;
		long long c1 = 1ll * xj * yi - 1ll * yj * xi;
		long long c2 = 1ll * xk * yj - 1ll * yk * xj;
		long long c3 = 1ll * xi * yk - 1ll * yi * xk;
		if (c1 + c2 + c3 > 0)
			tri[t] = make_tuple(i, k, j);
		G[i].push_back(j);
		G[i].push_back(k);
		G[j].push_back(i);
		G[j].push_back(k);
		G[k].push_back(i);
		G[k].push_back(j);
	}
}

int vis[6000];

int si, sj, sk, ti, tj, tk;
int mxh;

int dfs(int u, int fa)
{
	if (height[u] > mxh || vis[u] != -1)
		return -1;
	vis[u] = fa;
	if (u == si || u == sj || u == sk)
		return u;
	int i;
	for (int v: G[u])
		if ((i = dfs(v, u)) != -1)
			return i;
	return -1;
}

int main()
{
	freopen("hiking.in", "r", stdin);
	freopen("hiking.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		tri[i] = make_tuple(readPoint(), readPoint(), readPoint());
	init();
	int sx, sy, sz, tx, ty, tz;
	scanf("%d %d %d %d %d %d", &sx, &sy, &sz, &tx, &ty, &tz);
	int s = findTri(sx, sy);
	int t = findTri(tx, ty);
	if (s == t)
		printf("2\n%d %d %d\n%d %d %d\n", sx, sy, sz, tx, ty, tz);
	else
	{
		tie(si, sj, sk) = tri[s];
		tie(ti, tj, tk) = tri[t];
		int mi = 1e9;
		for (int i = 0; i < id.size(); ++i)
		{
			for (int j = 0; j < id.size(); ++j)
				vis[j] = -1;
			mxh = height[i];
			int last;
			if ((last = dfs(ti, -2)) != -1 || (last = dfs(tj, -2)) != -1 || (last = dfs(tk, -2)) != -1)
			{
				mi = min(mi, mxh);
			}
		}
		vector<int> ans;
		mxh = mi;
		int u;
		for (int j = 0; j < id.size(); ++j)
			vis[j] = -1;
		(u = dfs(ti, -2)) != -1 || (u = dfs(tj, -2)) != -1 || (u = dfs(tk, -2)) != -1;
		do
		{
			ans.push_back(u);
			u = vis[u];
		}
		while (u != -2);
		printf("%d\n", ans.size() + 2);
		printf("%d %d %d\n", sx, sy, sz);
		for (int i: ans)
			printf("%d %d %d\n", pos[i].first, pos[i].second, height[i]);
		printf("%d %d %d\n", tx, ty, tz);
	}
	return 0;
}
