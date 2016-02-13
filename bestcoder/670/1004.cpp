#include <cstdio>
#include <algorithm>

using namespace std;

struct Edge
{
	int u, v, w;
	bool operator<(const Edge &rhs) const
	{
		return w < rhs.w;
	}
};

int N, M;
Edge edge[15000];
int p[2001];
int con;

int findset(int x)
{
	return x == p[x] ? x : p[x] = findset(p[x]);
}

void reset()
{
	for (int i = 1; i <= N; ++i)
		p[i] = i;
	con = N;
}

void unionset(int i)
{
	int x = findset(edge[i].u);
	int y = findset(edge[i].v);
	if (x != y)
	{
		p[x] = y;
		con--;
	}
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d %d", &N, &M);
		for (int i = 0; i < M; ++i)
			scanf("%d %d %d", &edge[i].u, &edge[i].v, &edge[i].w);
		sort(edge, edge + M);
		int st = M - 1;
		reset();
		for (; st >= 0; --st)
		{
			unionset(st);
			if (con == 1)
				break;
		}
		if (st == -1)
		{
			puts("-1");
		}
		else
		{
			int ans = edge[M - 1].w - edge[st].w;
			for (; st >= 0; --st)
			{
				reset();
				for (int i = st; i < M && edge[i].w - edge[st].w < ans; ++i)
				{
					unionset(i);
					if (con == 1)
					{
						ans = min(ans, edge[i].w - edge[st].w);
						break;
					}
				}
			}
			printf("%d\n", ans);
		}
	}
	return 0;
}
