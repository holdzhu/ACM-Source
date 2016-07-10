#include <cstdio>

const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

int N, K;
char s[500][501];
int p[500 * 500];
int sum[501][501];
int cnt[500 * 500];
int vis[500 * 500];

int findset(int x)
{
	return x == p[x] ? x : p[x] = findset(p[x]);
}

inline int idx(int i, int j)
{
	return i * N + j;
}

void unionset(int u, int v)
{
	u = findset(u);
	v = findset(v);
	if (u != v)
	{
		p[u] = v;
		cnt[v] += cnt[u];
	}
}

int main()
{
	scanf("%d %d", &N, &K);
	for (int i = 0; i < N; ++i)
		scanf("%s", s[i]);
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			sum[i + 1][j + 1] = sum[i][j] - sum[i + 1][j] - sum[i][j + 1] + (s[i][j] == '.');
	for (int i = 0; i < N * N; ++i)
		p[i] = i, cnt[i] = 1;
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			if (s[i][j] == '.')
			{
				for (int k = 0; k < 4; ++k)
				{
					int ni = i + dx[k];
					int nj = j + dy[k];
					if (ni >= 0 && ni < N && nj >= 0 && nj < N)
						unionset(idx(i, j), idx(ni, nj));
				}
			}
	int tim = 1;
	int mx = 0;
	for (int i = 0; i < N - K + 1; ++i)
		for (int j = 0; j < N - K + 1; ++j)
		{
			int ans = 0;
			if (i > 0)
			{
				for (int k = 0; k < K; ++k)
				{
					int id = vis[findset(idx(i - 1, j + k))];
					if (id != tim)
					{
						id = tim;
						ans += cnt[findset(id)];
					}
				}
			}
			if (j > 0)
			{
				for (int k = 0; k < K; ++k)
				{
					int id = vis[findset(idx(i + k, j - 1))];
					if (id != tim)
					{
						id = tim;
						ans += cnt[findset(id)];
					}
				}
			}
			if (i + K < N)
			{
				for (int k = 0; k < K; ++k)
				{
					int id = vis[findset(idx(i + K, j + k))];
					if (id != tim)
					{
						id = tim;
						ans += cnt[findset(id)];
					}
				}
			}
			if (j + K < N)
			{
				for (int k = 0; k < K; ++k)
				{
					int id = vis[findset(idx(i + k, j + K))];
					if (id != tim)
					{
						id = tim;
						ans += cnt[findset(id)];
					}
				}
			}
			++tim;
		}
	return 0;
}
