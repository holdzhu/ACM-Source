#include <cstdio>

int n, m;
int last;
int s;

void dfs(int pos)
{
	if (pos == m)
	{
		s++;
		return;
	}
	int a = n ? (n - 1) / (m - pos) + 1 : 0;
	for (int i = a; i <= last && i <= n; ++i)
	{
		// printf("%d %d %d %d %d\n", i, last, a, n, pos);
		n -= i;
		int _last = last;
		last = i;
		dfs(pos + 1);
		last = _last;
		n += i;
	}
}

int main()
{
	while (scanf("%d %d", &n, &m) == 2)
	{
		s = 0;
		last = n;
		dfs(0);
		printf("%d\n", s);
	}
	return 0;
}
