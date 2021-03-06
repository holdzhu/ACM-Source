#include <cstdio>
#include <queue>
#include <vector>

using namespace std;

const int maxn = 1e6 + 10;
int ch[maxn][26];
int f[maxn];
bool val[maxn];
int sz = 1;
vector<int> G[maxn];
int id[maxn];
int N;
int tree[maxn * 2];
int in[maxn], out[maxn];
char s[1000001];

int insert(char *s)
{
	int u = 0;
	for (int i = 0; s[i]; ++i)
	{
		int c = s[i] - 'a';
		if (!ch[u][c])
			ch[u][c] = sz++;
		u = ch[u][c];
	}
	return u;
}

void getFail()
{
	queue<int> q;
	for (int c = 0; c < 26; ++c)
	{
		int u = ch[0][c];
		if (u)
		{
			q.push(u);
			G[0].push_back(u);
		}
	}
	while (!q.empty())
	{
		int r = q.front();
		q.pop();
		for (int c = 0; c < 26; ++c)
		{
			int u = ch[r][c];
			if (!u)
			{
				ch[r][c] = ch[f[r]][c];
				continue;
			}
			q.push(u);
			int v = f[r];
			while (v && !ch[v][c])
				v = f[v];
			f[u] = ch[v][c];
			G[ch[v][c]].push_back(u);
		}
	}
}

int lowbit(int x)
{
	return x & (-x);
}

void update(int x, int val)
{
	while (x <= N)
	{
		tree[x] += val;
		x += lowbit(x);
	}
}

int query(int x)
{
	int ret = 0;
	while (x)
	{
		ret += tree[x];
		x -= lowbit(x);
	}
	return ret;
}

void dfs(int u)
{
	in[u] = ++N;
	for (int v: G[u])
		dfs(v);
	out[u] = ++N;
}

int main()
{
	int n, k;
	scanf("%d %d", &n, &k);
	for (int i = 0; i < k; ++i)
	{
		scanf("%s", s);
		id[i] = insert(s);
	}
	getFail();
	dfs(0);
	for (int i = 0; i < k; ++i)
	{
		update(in[id[i]], 1);
		update(out[id[i]], -1);
		val[id[i]] = 1;
	}
	for (int i = 0; i < n; ++i)
	{
		char cmd;
		scanf(" %c", &cmd);
		if (cmd == '+')
		{
			int t;
			scanf("%d", &t);
			t--;
			if (val[id[t]])
				continue;
			update(in[id[t]], 1);
			update(out[id[t]], -1);
			val[id[t]] = 1;
		}
		else if (cmd == '-')
		{
			int t;
			scanf("%d", &t);
			t--;
			if (!val[id[t]])
				continue;
			update(in[id[t]], -1);
			update(out[id[t]], 1);
			val[id[t]] = 0;
		}
		else
		{
			scanf("%s", s);
			long long ans = 0;
			int u = 0;
			for (int i = 0; s[i]; ++i)
			{
				u = ch[u][s[i] - 'a'];
				ans += query(in[u]);
			}
			printf("%I64d\n", ans);
		}
	}
	return 0;
}
