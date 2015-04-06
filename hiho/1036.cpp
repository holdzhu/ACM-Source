#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

const int maxnode = 1000000;
const int sigma_size = 26;

int ch[maxnode][sigma_size];
bool val[maxnode];
int f[maxnode];
int sz = 1;

int idx(char c)
{
	return c - 'a';
}

void insert(char *s)
{
	int u = 0;
	int l = strlen(s);
	for (int i = 0; i < l; ++i)
	{
		if (ch[u][idx(s[i])] == 0)
		{
			ch[u][idx(s[i])] = sz++;
		}
		u = ch[u][idx(s[i])];
	}
	val[u] = true;
}

int main()
{
	int n;
	char s[1000001];
	scanf("%d", &n);
	memset(ch, 0, sizeof(ch));
	memset(val, 0, sizeof(val));
	while (n--)
	{
		scanf("%s", s);
		insert(s);
	}
	queue<int> q;
	for (int i = 0; i < sigma_size; ++i)
	{
		int u = ch[0][i];
		if (ch[0][i])
		{
			f[u] = 0;
			q.push(u);
		}
	}
	while (!q.empty())
	{
		int p = q.front();
		q.pop();
		for (int i = 0; i < sigma_size; ++i)
		{
			int u = ch[p][i];
			if (!u)
			{
				ch[p][i] = ch[f[p]][i];
				continue;
			}
			q.push(u);
			int v = f[p];
			while (v && !ch[v][i])
			{
				v = f[v];
			}
			f[u] = ch[v][i];
		}
	}
	scanf("%s", s);
	int u = 0;
	bool success = false;
	for (int i = 0; s[i]; ++i)
	{
		u = ch[u][idx(s[i])];
		if (val[u])
		{
			success = true;
			break;
		}
	}
	if (success)
	{
		printf("YES\n");
	}
	else
	{
		printf("NO\n");
	}
	return 0;
}
