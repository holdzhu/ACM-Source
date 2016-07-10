#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

const int inf = 1e9;

char s[101];
char t[5][21];
int cnt[5];
char tmp[101];
int diss[101];
int dist[101];
int dis[102][102];
bool isend[102];
int pos[101];
int p[101];

int main()
{
	int T;
	scanf("%d", &T);
	for (int kase = 1; kase <= T; ++kase)
	{
		int N;
		scanf("%d", &N);
		for (int i = 0; i <= N + 1; ++i)
			for (int j = 0; j <= N + 1; ++j)
				dis[i][j] = inf;
		for (int i = 1; i <= N; ++i)
		{
			int u;
			scanf("%d", &u);
			dis[u][i] = 1;
			isend[i] = true;
			isend[u] = false;
		}
		for (int i = 1; i <= N; ++i)
			if (isend[i])
				dis[i][N + 1] = 0;
		for (int k = 0; k <= N + 1; ++k)
			for (int i = 0; i <= N + 1; ++i)
				for (int j = 0; j <= N + 1; ++j)
					dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
		scanf("%s", s);
		int M;
		scanf("%d", &M);
		for (int i = 0; i < M; ++i)
		{
			scanf("%s", t[i]);
			cnt[i] = 0;
		}
		for (int ite = 0; ite < 100000; ++ite)
		{
			bool flag = true;
			for (int i = 0; i <= N; ++i)
				tmp[i] = 0, p[i] = i;
			random_shuffle(p + 1, p + 1 + N);
			for (int i = 1; i <= N; ++i)
			{
				int l = dis[0][p[i]];
				int r = N - dis[p[i]][N + 1];
				for (int j = 1; j < i; ++j)
				{
					if (dis[p[j]][p[i]] < inf)
						l = max(l, pos[p[j]] + dis[p[j]][p[i]]);
					if (dis[p[i]][p[j]] < inf)
						r = min(r, pos[p[j]] - dis[p[i]][p[j]]);
				}
				if (l <= r)
				{
					pos[p[i]] = rand() % (r - l + 1) + l;
					if (tmp[pos[p[i]] - 1])
					{
						flag = false;
						break;
					}
					tmp[pos[p[i]] - 1] = s[p[i] - 1];
				}
				else
				{
					flag = false;
					break;
				}
			}
			if (!flag)
			{
				--ite;
				continue;
			}
			for (int i = 0; i < M; ++i)
				if (strstr(tmp, t[i]))
					cnt[i]++;
		}
		printf("Case #%d:", kase);
		for (int i = 0; i < M; ++i)
			printf(" %.2f", cnt[i] * 0.00001);
		puts("");
	}
	return 0;
}
