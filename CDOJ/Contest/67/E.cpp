#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

struct Road
{
	int Xor, w;
};

int n;
vector<int> G[200000];
Road road[199999];
pair<int, int> RMQ[400000][20];
int curRMQ = 0;
int BIT[400001];
int curBIT = 1;
int last[200000];
int in[200000];
int out[200000];
int p[200000];

inline int lowbit(int x)
{
	return x & (-x);
}

int query(int x)
{
	int rnt = 0;
	while (x)
	{
		rnt += BIT[x];
		x -= lowbit(x);
	}
	return rnt;
}

void update(int x, int delta)
{
	while (x <= n * 2)
	{
		BIT[x] += delta;
		x += lowbit(x);
	}
}

inline pair<int, int> min(pair<int, int> a, pair<int, int> b)
{
	return a.second > b.second ? b : a;
}

void dfs(int x = 0, int fa = -1, int h = 0)
{
	last[x] = curRMQ;
	RMQ[curRMQ][0].first = x;
	RMQ[curRMQ++][0].second = h;
	p[x] = fa;
	if (fa != -1)
	{
		in[fa] = curBIT;
		update(curBIT++, road[fa].w);
	}
	for (int i = 0; i < G[x].size(); ++i)
	{
		int v = road[G[x][i]].Xor ^ x;
		if (fa != -1 && v == (road[fa].Xor ^ x))
		{
			continue;
		}
		dfs(v, G[x][i], h + 1);
		last[x] = curRMQ;
		RMQ[curRMQ][0].first = x;
		RMQ[curRMQ++][0].second = h;
	}
	if (fa != -1)
	{
		out[fa] = curBIT;
		update(curBIT++, -road[fa].w);
	}
}

int solve(int x)
{
	if (x == 0)
	{
		return 0;
	}
	return query(in[p[x]]);
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n - 1; ++i)
	{
		int u, v;
		scanf("%d %d %d", &u, &v, &road[i].w);
		u--;
		v--;
		road[i].Xor = u ^ v;
		G[u].push_back(i);
		G[v].push_back(i);
	}
	dfs();
	for (int i = 1; (1 << i) <= curRMQ; ++i)
	{
		for (int j = 0; j <= curRMQ - (1 << i); ++j)
		{
			RMQ[j][i] = min(RMQ[j][i - 1], RMQ[j + (1 << (i - 1))][i - 1]);
		}
	}
	int q;
	scanf("%d", &q);
	for (int i = 0; i < q; ++i)
	{
		int op;
		scanf("%d", &op);
		if (op == 1)
		{
			int u, v;
			scanf("%d %d", &u, &v);
			u--;
			v--;
			int la = last[u];
			int lb = last[v];
			int m;
			if (la > lb)
			{
				la ^= lb;
				lb ^= la;
				la ^= lb;
			}
			for (m = 1; 1 << m <= lb - la; ++m);
			int LCP = (min(RMQ[la][m - 1], RMQ[lb + 1 - (1 << (m - 1))][m - 1])).first;
			printf("%d\n", solve(u) - solve(LCP) + solve(v) - solve(LCP));
		}
		else
		{
			int id, w;
			scanf("%d %d", &id, &w);
			id--;
			int orig = road[id].w;
			update(in[id], w - orig);
			update(out[id], -w + orig);
			road[id].w = w;
		}
	}
	return 0;
}
