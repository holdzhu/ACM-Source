#include <cstdio>
#include <cstring>

int l;
char type[27];
int n, m;
bool G[200][2][200][2];
char s[201];
int col[200];
int colt[200];
char ans[201];

bool dfs(int u, int c)
{
	if (colt[u] == c)
	{
		return true;
	}
	if (colt[u] == 1 - c)
	{
		return false;
	}
	colt[u] = c;
	for (int i = 0; i < n; ++i)
	{
		if (i == u)
		{
			continue;
		}
		if (G[u][c][i][0])
		{
			if (!dfs(i, 0))
			{
				return false;
			}
		}
		if (G[u][c][i][1])
		{
			if (!dfs(i, 1))
			{
				return false;
			}
		}
		if (G[i][0][u][1 - c])
		{
			if (!dfs(i, 1))
			{
				return false;
			}
		}
		if (G[i][1][u][1 - c])
		{
			if (!dfs(i, 0))
			{
				return false;
			}
		}
	}
	return true;
}

inline int idx(char c)
{
	return c == 'V';
}

int main()
{
	scanf("%s", type);
	l = strlen(type);
	scanf("%d %d", &n, &m);
	memset(G, 0, sizeof G);
	for (int i = 0; i < m; ++i)
	{
		int pos1, pos2;
		char t1[2], t2[2];
		scanf("%d %s %d %s", &pos1, t1, &pos2, t2);
		pos1--;
		pos2--;
		G[pos1][idx(t1[0])][pos2][idx(t2[0])] = true;
	}
	scanf("%s", s);
	bool flag = false;
	for (int limit = n; limit >= 0; --limit)
	{
		memset(col, -1, sizeof col);
		flag = true;
		for (int i = 0; i < n; ++i)
		{
			int mi[2] = {-1, -1};
			if (i < limit)
			{
				int t = idx(type[s[i] - 'a']);
				if (memcpy(colt, col, sizeof colt), dfs(i, t))
				{
					memcpy(col, colt, sizeof colt);
					ans[i] = s[i];
				}
				else
				{
					flag = false;
					break;
				}
			}
			else if (i == limit)
			{
				for (int j = s[i] - 'a' + 1; j < l; ++j)
				{
					if (mi[idx(type[j])] == -1)
					{
						mi[idx(type[j])] = j;
					}
				}
				if (s[i] - 'a' == l - 1)
				{
					flag = false;
					break;
				}
				int t = idx(type[s[i] - 'a' + 1]);
				if (memcpy(colt, col, sizeof colt), dfs(i, t))
				{
					memcpy(col, colt, sizeof colt);
					ans[i] = s[i] + 1;
				}
				else if (mi[1 - t] != -1 && (memcpy(colt, col, sizeof colt), dfs(i, 1 - t)))
				{
					memcpy(col, colt, sizeof colt);
					ans[i] = mi[1 - t] + 'a';
				}
				else
				{
					flag = false;
					break;
				}
			}
			else
			{
				for (int j = 0; j < l; ++j)
				{
					if (mi[idx(type[j])] == -1)
					{
						mi[idx(type[j])] = j;
					}
				}
				int t = idx(type[0]);
				if (memcpy(colt, col, sizeof colt), dfs(i, t))
				{
					memcpy(col, colt, sizeof colt);
					ans[i] = mi[t] + 'a';
				}
				else if (mi[1 - t] != -1 && (memcpy(colt, col, sizeof colt), dfs(i, 1 - t)))
				{
					memcpy(col, colt, sizeof colt);
					ans[i] = mi[1 - t] + 'a';
				}
				else
				{
					flag = false;
					break;
				}
			}
		}
		if (flag)
		{	
			break;
		}
	}
	if (flag)
	{
		ans[n] = 0;
		printf("%s\n", ans);
	}
	else
	{
		printf("-1\n");
	}
	return 0;
}
