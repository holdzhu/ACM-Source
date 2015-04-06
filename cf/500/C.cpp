#include <cstdio>
#include <cstring>

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	int w[n];
	int b[m];
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &w[i]);
	}
	for (int i = 0; i < m; ++i)
	{
		scanf("%d", &b[i]);
		b[i]--;
	}
	bool a[n];
	memset(a, 0, sizeof(a));
	int c[n];
	int pos = 0;
	int p[n];
	for (int i = 0; i < m; ++i)
	{
		if (!a[b[i]])
		{
			c[pos] = b[i];
			p[b[i]] = pos;
			pos++;
			a[b[i]] = true;
		}
	}
	int ans = 0;
	for (int i = 1; i < m; ++i)
	{
		for (int j = p[b[i]]; j > 0; --j)
		{
			c[j] = c[j - 1];
			p[c[j]] = j;
			ans += w[c[j]];
		}
		c[0] = b[i];
		p[b[i]] = 0;
	}
	printf("%d\n", ans);
	return 0;
}
