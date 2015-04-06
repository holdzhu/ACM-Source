#include <cstdio>
#include <cstring>

const int maxnode = 1000000;
const int sigma_size = 26;

int ch[maxnode][sigma_size];
int val[maxnode];
int sz = 1;

int idx(char c)
{
	return c - 'a';
}

void insert(char *s)
{
	int u = 0;
	int n = strlen(s);
	for (int i = 0; i < n; ++i)
	{
		val[u]++;
		if (!ch[u][idx(s[i])])
		{
			memset(ch[sz], 0, sizeof(ch[sz]));
			val[sz] = 0;
			ch[u][idx(s[i])] = sz++;
		}
		u = ch[u][idx(s[i])];
	}
	val[u]++;
}

int query(char *s)
{
	int u = 0;
	int n = strlen(s);
	for (int i = 0; i < n; ++i)
	{
		if (!ch[u][idx(s[i])])
		{
			return 0;
		}
		u = ch[u][idx(s[i])];
	}
	return val[u];
}

int main()
{
	int n, m;
	char s[11];
	memset(ch[0], 0, sizeof(ch[0]));
	val[0] = 0;
	scanf("%d", &n);
	while (n--)
	{
		scanf("%s", s);
		insert(s);
	}
	scanf("%d", &m);
	while (m--)
	{
		scanf("%s", s);
		printf("%d\n", query(s));
	}
	return 0;
}
