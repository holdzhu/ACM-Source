#include <cstdio>

const int dx[] = {0, 0, 1, -1, 1, 1, -1, -1};
const int dy[] = {1, -1, 0, 0, -1, 1, -1, 1};

int n, m;
int p[500 * 500 + 2];
char s[500][501];
int L;
int R;

int findset(int x)
{
	return x == p[x] ? x : p[x] = findset(p[x]);
}

int idx(int x, int y)
{
	if (x < 0 || x >= n)
		return -1;
	if (y < 0)
		return L;
	if (y >= m)
		return R;
	return x * m + y;
}

void update(int x, int y)
{
	for (int j = 0; j < 8; ++j)
	{
		int nx = x + dx[j];
		int ny = y + dy[j];
		int id = idx(x, y);
		int nid = idx(nx, ny);
		if (nid == -1)
			continue;
		if (ny >= 0 && ny < m && s[nx][ny] == '0')
			continue;
		int u = findset(id);
		int v = findset(nid);
		p[u] = v;
	}
	s[x][y] = '1';
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d %d", &n, &m);
		int ans = -1;
		L = n * m;
		R = L + 1;
		for (int i = 0; i < n * m + 2; ++i)
			p[i] = i;
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)
				s[i][j] = '0';
		for (int i = 0; i < n; ++i)
		{
			scanf("%s", s[i]);
			for (int j = 0; j < m; ++j)
				if (s[i][j] == '1')
					update(i, j);
		}
		if (findset(L) == findset(R))
			ans = 0;
		int Q;
		scanf("%d", &Q);
		for (int i = 0; i < Q; ++i)
		{
			int x, y;
			scanf("%d %d", &x, &y);
			update(x, y);
			if (ans == -1 && findset(L) == findset(R))
				ans = i + 1;
		}
		printf("%d\n", ans);
	}
	return 0;
}
