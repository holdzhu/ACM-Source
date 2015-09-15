#include <cstdio>
#include <bitset>

std::bitset<300002> s;

int main()
{
	int n, m;
	scanf("%d %d ", &n, &m);
	int ans = 0;
	bool last = 0;
	for (int i = 1; i <= n; ++i)
	{
		char c = getchar();
		if (c == '.')
		{
			ans++;
			if (!last)
			{
				ans--;
			}
		}
		last = s[i] = c == '.';
	}
	for (int i = 0; i < m; ++i)
	{
		int x;
		char c[2];
		scanf("%d %s", &x, c);
		if (c[0] == '.' && !s[x])
		{
			ans += s[x - 1] + s[x + 1];
		}
		else if (c[0] != '.' && s[x])
		{
			ans -= s[x - 1] + s[x + 1];
		}
		s[x] = c[0] == '.';
		printf("%d\n", ans);
	}
	return 0;
}
