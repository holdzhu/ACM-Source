#include <cmath>
#include <cstdio>

int x[1000];
int y[1000];
int z[1000];
int vx[1000];
int vy[1000];
int vz[1000];
double dis[1000];
bool vis[1000];

int main()
{
	int T;
	scanf("%d", &T);
	for (int kase = 1; kase <= T; ++kase)
	{
		int N, S;
		scanf("%d %d", &N, &S);
		for (int i = 0; i < N; ++i)
			scanf("%d %d %d %d %d %d", &x[i], &y[i], &z[i], &vx[i], &vy[i],
				  &vz[i]);
		for (int i = 1; i < N; ++i)
			dis[i] = 1e233;
		dis[0] = 0;
		for (int i = 0; i < N; ++i)
			vis[i] = false;
		for (int i = 0; i < N - 1; ++i)
		{
			int id = -1;
			for (int j = 0; j < N; ++j)
				if (!vis[j] && (id == -1 || dis[id] > dis[j]))
					id = j;
			vis[id] = true;I
			for (int j = 0; j < N; ++j)
				dis[j] =
					fmin(dis[j], fmax(dis[id], sqrt((x[id] - x[j]) * (x[id] - x[j]) +
												(y[id] - y[j]) * (y[id] - y[j]) +
												(z[id] - z[j]) * (z[id] - z[j]))));
		}
		printf("Case #%d: %.7f\n", kase, dis[1]);
	}
	return 0;
}
