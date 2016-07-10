#include <algorithm>
#include <cstdio>
#include <map>
#include <vector>

using namespace std;

const int maxn = 1e5;

struct Value
{
	int cnt;
	long long sum;
	long long ans;
	Value(int cnt = 0, long long sum = 0, long long ans = 0)
		: cnt(cnt), sum(sum), ans(ans)
	{
	}
};

vector<int> fac[maxn + 1];

struct Node
{
	map<int, Value> mp;
	int delta;
	Node(int x0)
	{
		for (int v : fac[x0])
			mp[v] = (Value){1, 0, 0};
		delta = 0;
	}
};

void unionNode(Node &A, Node &B)
{
	if (A.mp.size() < B.mp.size())
		swap(A, B);
	for (auto &p : B.mp)
	{
		Value &a = A.mp[p.first];
		Value &b = p.second;
		Value v;
		v.cnt = a.cnt + b.cnt;
		v.sum = a.sum + b.sum + 1ll * (-A.delta + B.delta) * b.cnt;
		v.ans = a.ans + b.ans + a.cnt * (b.sum + 1ll * B.delta * b.cnt) +
				b.cnt * (a.sum + 1ll * A.delta * a.cnt);
		a = v;
	}
	delete &B;
}

vector<int> G[maxn + 1];
int a[maxn + 1];
Node *node[maxn + 1];

void dfs(int u, int fa = -1)
{
	node[u] = new Node(a[u]);
	for (int v : G[u])
	{
		if (v == fa)
			continue;
		dfs(v, u);
		unionNode(*node[u], *node[v]);
	}
	node[u]->delta++;
}

long long f[maxn + 1];

int main()
{
	for (int i = 1; i <= maxn; ++i)
		for (int j = 1; i * j <= maxn; ++j)
			fac[i * j].push_back(i);
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	for (int i = 0; i < n - 1; ++i)
	{
		int u, v;
		scanf("%d %d", &u, &v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dfs(1);
	for (auto &v : node[1]->mp)
		f[v.first] = v.second.ans;
	for (int i = maxn; i >= 1; --i)
		for (int j = i + i; j <= maxn; j += i)
			f[i] -= f[j];
	printf("%lld\n", f[1]);
	return 0;
}
