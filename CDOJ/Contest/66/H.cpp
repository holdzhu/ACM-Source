#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

vector<int> G[10000];
int sz;
int NIC1[10000];
int NIC2[10000];

void dfs(int x, int fa, int no)
{
	NIC1[x] = no;
	bool first = true;
	if (G[x].size() == 1 && fa == 0)
	{
		NIC2[x] = NIC2[fa];
	}
	else if (G[x].size() == 1 && fa != -1)
	{
		NIC2[x] = NIC1[fa];
	}
	else
	{
		NIC2[x] = sz++;
		for (int i = 0; i < G[x].size(); ++i)
		{
			if (G[x][i] != fa)
			{
				if (first && fa == -1)
				{
					dfs(G[x][i], x, no);
					first = false;
				}
				else
				{
					dfs(G[x][i], x, NIC2[x]);
				}
			}
		}
	}
}

int main()
{
	int n;
	scanf("%d", &n);
	memset(NIC2, -1, sizeof NIC2);
	for (int i = 0; i < n - 1; ++i)
	{
		int u, v;
		scanf("%d %d", &u, &v);
		u--;
		v--;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	sz = 1;
	dfs(0, -1, 0);
	for (int i = 0; i < n; ++i)
	{
		printf("%d %d\n", NIC1[i], NIC2[i]);
	}
	return 0;
}
