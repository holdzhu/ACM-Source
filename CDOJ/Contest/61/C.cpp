#include <cstdio>
#include <cstring>

bool used[26];
bool head[26];
int n;
char s[10][11];
int d[26];
int queue[10];
int top;
int next[11];

inline long long readLongLong(char* sp)
{
	long long rnt = 0;
	for (int i = 0; sp[i] != -1; ++i)
	{
		rnt *= 10;
		rnt += d[sp[i]] - 1;
	}
	return rnt;
}

int dfs(int x)
{
	if (x < top)
	{
		int rnt = 0;
		d[queue[x]] = 0;
		while (next[d[queue[x]]])
		{
			int last = d[queue[x]];
			d[queue[x]] = next[d[queue[x]]];
			if (!head[queue[x]] || d[queue[x]] != 1)
			{
				next[last] = next[d[queue[x]]];
				rnt += dfs(x + 1);
				next[last] = d[queue[x]];
			}
		}
		return rnt;
	}
	else
	{
		long long add = -readLongLong(s[n - 1]);
		for (int i = 0; i < n - 1; ++i)
		{
			add += readLongLong(s[i]);
			if (add > 0)
			{
				return 0;
			}
		}
		return add == 0;
	}
}

int main()
{
	while (scanf("%d", &n) == 1)
	{
		memset(used, 0, sizeof used);
		memset(head, 0, sizeof head);
		for (int i = 0; i < n; ++i)
		{
			scanf("%s", s[i]);
			int l = strlen(s[i]);
			for (int j = 0; j < l; ++j)
			{
				s[i][j] -= 'A';
				used[s[i][j]] = true;
			}
			s[i][l] = -1;
			head[s[i][0]] = true;
		}
		top = 0;
		for (int i = 0; i < 26; ++i)
		{
			if (used[i])
			{
				queue[top++] = i;
			}
		}
		for (int i = 0; i < 10; ++i)
		{
			next[i] = i + 1;
		}
		next[10] = 0;
		printf("%d\n", dfs(0));
	}
	return 0;
}
