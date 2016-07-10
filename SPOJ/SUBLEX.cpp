#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

const int maxn = 90000;

int last, cnt, root;
char s[maxn + 1];
int ch[maxn * 2][26];
int mx[maxn * 2];
int fa[maxn * 2];
int deg[maxn * 2];
vector<int> G[maxn * 2];
unsigned sz[maxn * 2];

int main()
{
	scanf("%s", s);
	int n = strlen(s);
	root = last = ++cnt;
	for (int i = 0; i < n; ++i)
	{
		int x = s[i] - 'a';
		int np = ++cnt;
		int p = last;
		mx[np] = mx[p] + 1;
		while (p && !ch[p][x])
			ch[p][x] = np, p = fa[p];
		if (!p)
			fa[np] = root;
		else
		{
			int q = ch[p][x];
			if (mx[q] == mx[p] + 1)
				fa[np] = q;
			else
			{
				int nq = ++cnt;
				mx[nq] = mx[p] + 1;
				for (int j = 0; j < 26; ++j)
					ch[nq][j] = ch[q][j];
				fa[nq] = fa[q];
				fa[np] = fa[q] = nq;
				while (p && ch[p][x] == q)
					ch[p][x] = nq, p = fa[p];
			}
		}
		last = np;
	}
	for (int i = 1; i <= cnt; ++i)
		for (int j = 0; j < 26; ++j)
			if (ch[i][j])
			{
				++deg[i];
				G[ch[i][j]].push_back(i);
			}
	queue<int> q;
	for (int i = 1; i <= cnt; ++i)
		if (!deg[i])
			q.push(i);
	while (!q.empty())
	{
		int u = q.front();
		q.pop();
		++sz[u];
		for (int v: G[u])
		{
			sz[v] += sz[u];
			if (--deg[v] == 0)
				q.push(v);
		}
	}
	int Q;
	scanf("%d", &Q);
	while (Q--)
	{
		int K;
		scanf("%d", &K);
		int p = root;
		while (K > 0)
		{
			int sum = 0;
			for (int i = 0; i < 26; ++i)
				if (sum + sz[ch[p][i]] >= K)
				{
					K -= sum + 1;
					putchar('a' + i);
					p = ch[p][i];
					break;
				}
				else
					sum += sz[ch[p][i]];
		}
		puts("");
	}
	return 0;
}
