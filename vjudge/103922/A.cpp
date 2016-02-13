#include <cstdio>
#include <vector>

using namespace std;

vector<int> G[300];

int main()
{
	int n, k;
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; ++i)
	{
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		u--, v--, w--;
		G[u].push_back(v);
		G[u].push_back(w);
	}
	int q;
	scanf("%d", &q);
	while (q--)
	{
		int u, v;
		scanf("%d %d", & );
	}
	return 0;
}
