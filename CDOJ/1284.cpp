#include <cstdio>
#include <unordered_map>
#include <vector>

using namespace std;

struct Node
{
	unordered_map<int, int> mp;
	int xr;
	Node(int xr) : xr(xr)
	{
		mp.max_load_factor(0.25);
		mp[0] = 1;
	}
};

vector<int> G[100001];
Node *node[100001];
long long ans;

void update(Node *u, Node *v)
{
	if (u->mp.size() < v->mp.size())
		swap(u, v);
	for (auto p: v->mp)
		ans += 1ll * p.second * u->mp[p.first ^ u->xr ^ v->xr];
}

Node *unionNode(Node *u, Node *v)
{
	if (u->mp.size() < v->mp.size())
		swap(u, v);
	for (auto p: v->mp)
		u->mp[p.first ^ u->xr ^ v->xr] += p.second;
	delete v;
	return u;
}

void dfs(int u, int fa)
{
	node[u] = new Node(u);
	for (int v : G[u])
	{
		if (v == fa)
			continue;
		dfs(v, u);
		update(node[u], node[v]);
		node[v]->xr ^= u;
		node[u] = unionNode(node[u], node[v]);
	}
}

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n - 1; ++i)
	{
		int u, v;
		scanf("%d %d", &u, &v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dfs(1, 0);
	printf("%lld\n", ans);
	return 0;
}
