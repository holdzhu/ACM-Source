#include <cstdio>
#include <cstring>

char s[1000001];
int p[1000001];
bool b[1000001];

inline int max(int a, int b)
{
	return a > b ? a : b;
}

bool check(int st, int en)
{
	while (st > en)
	{
		st = p[st];
	}
	return st == en;
}

int main()
{
	int n, k;
	scanf("%d %d", &n, &k);
	scanf("%s", s);
	memset(p, 0, sizeof p);
	p[0] = -1;
	for (int i = 0; i < n; ++i)
	{
		int u = p[i];
		while (u >= 0 && s[u] != s[i])
		{
			u = p[u];
		}
		u++;
		p[i + 1] = u;
	}
	memset(b, 0, sizeof b);
	int mx = 0;
	for (int l = 1; l <= n / k; ++l)
	{
		if (l % (l * k - p[l * k]) == 0)
		{
			b[l * k - 1] = true;
			mx = max(mx, l * k - 1);
			for (int i = max(1, mx - l * k); i <= l && l * k + i - 1 < n; ++i)
			{
				if (s[l * k + i - 1] == s[l * (k - 1) + i - 1])
				{
					b[l * k + i - 1] = true;
					mx = max(mx, l * k + i - 1);
				}
				else
				{
					break;
				}
			}
		}
	}
	for (int i = 0; i < n; ++i)
	{
		printf("%d", b[i]);
	}
	printf("\n");
	return 0;
}
