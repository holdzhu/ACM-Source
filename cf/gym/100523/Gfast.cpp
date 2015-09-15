#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int a, c, k, m, n;
char s[100001];
int fa[1000000];
int fail[100001];
int ll[100001];
int f[1000001];
int tf[1000001];
int jump[2][100001];
int p[1000000];
int fw[1000000];

void getfail(char* P, int* f, int m)
{
	f[0] = f[1] = 0;
	for (int i = 1; i < m; ++i)
	{
		int j = f[i];
		while (j && P[i] != P[j])
		{
			j = f[j];
		}
		f[i + 1] = P[i] == P[j] ? j + 1 : 0;
	}
}

int find(int x)
{
	return x == p[x] ? x : p[x] = find(p[x]);
}

int dfs(int u)
{
	return f[u] >= 0 ? f[u] : f[u] = jump[u >= m / 2][dfs(fa[u])];
}

int main()
{
	scanf("%d %d %d %d %d", &a, &c, &k, &m, &n);
	scanf("%s", s);
	for (int i = 0; i < m; ++i)
	{
		p[i] = i;
	}
	for (int i = 0; i < m; ++i)
	{
		fa[i] = (1ll * i * a + c) / k % m;
		p[find(i)] = p[find(fa[i])];
	}
	for (int i = 0; i < n / 2; ++i)
	{
		swap(s[i], s[n - 1 - i]);
	}
	getfail(s, fail, n);
	for (int i = 0; i <= n; ++i)
	{
		for (int j = 0; j < 2; ++j)
		{
			jump[j][i] = s[i] - '0' == j ? i + 1 : jump[j][fail[i]];
		}
	}
	memset(f, -1, sizeof f);
	for (int i = 1; i <= n; ++i)
	{
		ll[i - fail[i]] = i;
	}
	for (int i = 0; i < m; ++i)
	{
		if (find(fa[i]) == i)
		{
			int len = 0;
			int z = i;
			while (1)
			{
				fw[fa[z]] = z;
				len++;
				z = fa[z];
				if (z == i)
				{
					break;
				}
			}
			int j = 0;
			bool flag = false;
			for (int i = 0; i < len + min(n, len) - 1; ++i)
			{
				j = jump[z >= m / 2][j];
				f[z] = max(f[z], j);
				z = fw[z];
				if (j == len)
				{
					flag = true;
				}
			}
			if (flag && ll[len])
			{
				getfail(s + ll[len] - len, tf, len);
				j = 0;
				for (int i = 0; i < len + len - 1; ++i)
				{
					while (j && s[ll[len] - len + j] != (z >= m / 2) + '0')
					{
						j = tf[j];
					}
					j += s[ll[len] - len + j] == (z >= m / 2) + '0';
					f[z] = max(f[z], j + ll[len] - len);
					z = fw[z];
					if (j == len)
					{
						j = tf[j];
					}
				}
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < m; ++i)
	{
		dfs(i);
		if (f[fa[i]] == n)
		{
			ans++;
		}
	}
	printf("%d\n", ans);
	return 0;
}
