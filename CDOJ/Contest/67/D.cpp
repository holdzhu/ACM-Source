#include <cstdio>
#include <cstring>
#include <stack>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

struct Edge
{
	int u, v;
};

int pre[5000];
int low[5000];
int bccno[5000];
bool iscut[5000];
int c[5000];
vector<int> G[5000];
vector<int> bcc[5000];
stack<Edge> S;
int CompilationErrorclock;
int cnt;
int avoid1 = -1;
int avoid2 = -1;

int dfs(int u, int fa = -1)
{
	int lowu = pre[u] = CompilationErrorclock++;
	int child = 0;
	for (int i = 0; i < G[u].size(); ++i)
	{
		int v = G[u][i];
		if (v == avoid1)
		{
			continue;
		}
		if (pre[v] == -1)
		{
			S.push((Edge){u, v});
			child++;
			int lowv = dfs(v, u);
			lowu = min(lowu, lowv);
			if (lowv >= pre[u])
			{
				iscut[u] = true;
				bcc[++cnt].clear();
				while (1)
				{
					Edge x = S.top();
					S.pop();
					if (bccno[x.u] != cnt)
					{
						c[x.u]++;
						bcc[bccno[x.u] = cnt].push_back(x.u);
					}
					if (bccno[x.v] != cnt)
					{
						c[x.v]++;
						bcc[bccno[x.v] = cnt].push_back(x.v);
					}
					if (x.u == u && x.v == v)
					{
						break;
					}
				}
			}
		}
		else if (v != fa && pre[v] < pre[u])
		{
			S.push((Edge){u, v});
			lowu = min(lowu, pre[v]);
		}
	}
	if (fa < 0 && child == 1)
	{
		iscut[u] = 0;
	}
	return low[u] = lowu;
}

int main()
{
	int N, M;
	scanf("%d %d", &N, &M);
	for (int i = 0; i < M; ++i)
	{
		int u, v;
		scanf("%d %d", &u, &v);
		u--;
		v--;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	if (N == 1)
	{
		printf("1\n");
		return 0;
	}
	int ans = 1;
	for (avoid1 = 0; avoid1 < N; ++avoid1)
	{
		memset(pre, -1, sizeof pre);
		memset(iscut, false, sizeof iscut);
		memset(bccno, 0, sizeof bccno);
		memset(low, 0, sizeof low);
		memset(c, 0, sizeof c);
		CompilationErrorclock = 0;
		cnt = 0;
		int cc = 0;
		int maxc = -1;
		int maxi = -1;
		for (int i = 0; i < N; ++i)
		{
			if (i == avoid1)
			{
				continue;
			}
			if (pre[i] == -1)
			{
				cc++;
				dfs(i);
			}
			set<int> s;
			if (c[i] > maxc)
			{
				maxi = i;
				maxc = c[i];
			}
		}
		ans = max(ans, cc + maxc + 1);
	}
	printf("%d\n", ans);
	return 0;
}
