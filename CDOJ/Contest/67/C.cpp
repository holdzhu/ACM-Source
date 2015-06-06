#include <cstdio>
#include <cstring>
#include <climits>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Portal
{
	int v, c, d;
};

int N, M;
int Sp, Tp, St;
Portal portal[500001];
vector<int> G[100001];
int fa[500001];
int tim[100001];
int zz[100001];
bool inq[100001];
int lastportal[100001];
int ans[500001];

bool cmp(const int& a, const int& b)
{
	return portal[a].c > portal[b].c;
}

int main()
{
	scanf("%d %d", &N, &M);
	for (int i = 0; i < M; ++i)
	{
		int u;
		scanf("%d %d %d %d", &u, &portal[i].v, &portal[i].c, &portal[i].d);
		u--;
		portal[i].v--;
		G[u].push_back(i);
	}
	scanf("%d %d %d %d", &Sp, &Tp, &St, &portal[M].c);
	Sp--;
	Tp--;
	portal[M].v = N;
	G[Tp].push_back(M);
	for (int i = 0; i <= N; ++i)
	{
		sort(G[i].begin(), G[i].end(), cmp);
		tim[i] = INT_MAX;
	}
	memset(zz, 0, sizeof zz);
	memset(inq, 0, sizeof inq);
	queue<int> q;
	q.push(Sp);
	tim[Sp] = St;
	inq[Sp] = true;
	lastportal[Sp] = -1;
	while (!q.empty())
	{
		int u = q.front();
		q.pop();
		inq[u] = false;
		int t = tim[u];
		int lp = lastportal[u];
		for (; zz[u] < (int)G[u].size() && portal[G[u][zz[u]]].c >= t; ++zz[u])
		{
			int v = portal[G[u][zz[u]]].v;
			int d = portal[G[u][zz[u]]].d;
			if (tim[v] > d)
			{
				fa[G[u][zz[u]]] = lp;
				lastportal[v] = G[u][zz[u]];
				tim[v] = d;
				if (!inq[v])
				{
					inq[v] = true;
					q.push(v);
				}
			}
		}
	}
	if (tim[N] == INT_MAX)
	{
		printf("-1\n");
	}
	else
	{
		int cnt = 0;
		int p = fa[lastportal[N]];
		while (p != -1)
		{
			ans[cnt++] = p;
			p = fa[p];
		}
		printf("%d\n", cnt);
		for (int i = cnt - 1; i >= 0; --i)
		{
			printf("%d", ans[i] + 1);
			if (i)
			{
				printf(" ");
			}
		}
		printf("\n");
	}
	return 0;
}
