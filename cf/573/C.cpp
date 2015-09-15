#include <cstdio>
#include <vector>

using namespace std;

vector<int> G[100001];
vector<int> ID[100001];
bool good[100001];
bool cut[100001];

int dfs1(int u, int fa, int famx)
{

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
		ID[u].push_back(i);
		G[v].push_back(u);
		ID[v].push_back(i);
	}
	return 0;
}
