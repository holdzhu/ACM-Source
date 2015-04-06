#include <cstdio>
#include <set>
using namespace std;

int a[1000][1000];
int p[1000000];

int find(int x)
{
	if (x < 0 || p[x] < 0)
	{
		return -1;
	}
	return x == p[x] ? x : p[x] = find(p[x]);
}

int main()
{
	int Z;
	scanf("%d", &Z);
	while (Z--)
	{
		int n, m;
		scanf("%d %d", &n, &m);
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				scanf("%d", &a[i][j]);
			}
		}
		int T;
		scanf("%d", &T);
		while (T--)
		{
			int t;
			scanf("%d", &t);
			for (int i = 0; i < n; ++i)
			{
				for (int j = 0; j < m; ++j)
				{
					if (a[i][j] > t)
					{
						int u = find((i - 1) * m + j);
						int l = j > 0 ? find(i * m + j - 1) : -1;
						if (u >= 0 && l >= 0)
						{
							p[u] = l;
							p[i * m + j] = l;
						}
						else if (u >= 0)
						{
							p[i * m + j] = u;
						}
						else if (l >= 0)
						{
							p[i * m + j] = l;
						}
						else
						{
							p[i * m + j] = i * m + j;
						}
					}
					else
					{
						p[i * m + j] = -1;
					}
				}
			}
			set<int> s;
			s.insert(-1);
			for (int i = 0; i < n; ++i)
			{
				for (int j = 0; j < m; ++j)
				{
					s.insert(find(i * m + j));
				}
			}
			printf("%d ", s.size() - 1);
		}
		printf("\n");
	}
	return 0;
}
