#include <cstdio>
#include <set>

using namespace std;

const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};
char s[1001][1001];
int p[1000000], c[1000000];

int findset(int x)
{
	return x == p[x] ? x : p[x] = findset(p[x]);
}

void unionset(int u, int v)
{
	int x = findset(u);
	int y = findset(v);
	if (x != y)
	{
		p[x] = y;
		c[y] += c[x];
	}
}

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; ++i)
		scanf("%s", s[i]);
	for (int i = 0; i < n * m; ++i)
		p[i] = i, c[i] = 1;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			if (s[i][j] == '.')
			{
				if (s[i + 1][j] == '.')
					unionset(i * m + j, (i + 1) * m + j);
				if (s[i][j + 1] == '.')
					unionset(i * m + j, i * m + j + 1);
			}
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (s[i][j] == '.')
				putchar(s[i][j]);
			else
			{
				set<int> st;
				for (int k = 0; k < 4; ++k)
				{
					int x = i + dx[k];
					int y = j + dy[k];
					if (x >= 0 && y >= 0 && x < n && y < m && s[x][y] == '.')
						st.insert(findset(x * m + y));
				}
				int ans = 1;
				for (int v: st)
					ans += c[v];
				printf("%d", ans % 10);
			}
		}
		puts("");
	}
	return 0;
}
