#include <cstdio>
#include <stack>
#include <functional>
#include <algorithm>

using namespace std;

int s[3000][3000];
int rm[3000][3000];
int lm[3000][3000];
int dm[3000][3000];
int l[2][3000];
int r[2][3000];
stack<pair<int, int> > stk;

int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		int n, m;
		scanf("%d %d", &n, &m);
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				scanf("%d", &s[i][j]);
			}
		}
		if (n <= 2 && m <= 2)
		{
			printf("%d\n", n * m);
			continue;
		}
		for (int i = 0; i < n; ++i)
		{
			lm[i][0] = lm[i][1] = 0;
			for (int j = 2; j < m; ++j)
			{
				if (s[i][j] - s[i][j - 1] == s[i][j - 1] - s[i][j - 2])
				{
					lm[i][j] = lm[i][j - 1];
				}
				else
				{
					lm[i][j] = j - 1;
				}
			}
		}
		for (int i = 0; i < n; ++i)
		{
			rm[i][m - 1] = rm[i][m - 2] = m - 1;
			for (int j = m - 3; j >= 0; --j)
			{
				if (s[i][j] - s[i][j + 1] == s[i][j + 1] - s[i][j + 2])
				{
					rm[i][j] = rm[i][j + 1];
				}
				else
				{
					rm[i][j] = j + 1;
				}
			}
		}
		for (int j = 0; j < m; ++j)
		{
			dm[n - 1][j] = dm[n - 2][j] = n - 1;
			for (int i = n - 3; i >= 0; --i)
			{
				if (s[i][j] - s[i + 1][j] == s[i + 1][j] - s[i + 2][j])
				{
					dm[i][j] = dm[i + 1][j];
				}
				else
				{
					dm[i][j] = i + 1;
				}
			}
		}
		int ans = 1;
		bool cur = 0;
		for (int i = 0; i < n; ++i)
		{
			stk.push(make_pair(i - 1, -1));
			for (int j = 0; j < m; ++j)
			{
				while (stk.top().first >= dm[i][j])
				{
					stk.pop();
				}
				l[cur][j] = stk.top().second + 1;
				stk.push(make_pair(dm[i][j], j));
			}
			while (!stk.empty())
			{
				stk.pop();
			}
			stk.push(make_pair(i - 1, m));
			for (int j = m - 1; j >= 0; --j)
			{
				while (stk.top().first >= dm[i][j])
				{
					stk.pop();
				}
				r[cur][j] = stk.top().second - 1;
				stk.push(make_pair(dm[i][j], j));
			}
			while (!stk.empty())
			{
				stk.pop();
			}
			for (int j = 0; j < m; ++j)
			{
				if (j == 0 || j == m - 1 || s[i][j] - s[i][j - 1] != s[i][j + 1] - s[i][j])
				{
					ans = max(ans, rm[i][j] - j + 1);
					ans = max(ans, j - lm[i][j] + 1);
				}
				else
				{
					ans = max(ans, rm[i][j] - lm[i][j] + 1);
				}
			}
			if (i)
			{
				for (int j = 0; j < m; ++j)
				{
					if (j == 0 || j == m - 1 || s[i][j] - s[i][j - 1] != s[i][j + 1] - s[i][j] ||
						s[i - 1][j] - s[i - 1][j - 1] != s[i - 1][j + 1] - s[i - 1][j])
					{
						ans = max(ans, (min(min(r[cur][j], r[!cur][j]), min(rm[i][j], rm[i - 1][j])) - j + 1) * (dm[i - 1][j] - i + 2));
						ans = max(ans, (j - max(max(l[cur][j], l[!cur][j]), max(lm[i][j], lm[i - 1][j])) + 1) * (dm[i - 1][j] - i + 2));
					}
					else
					{
						ans = max(ans, (min(min(r[cur][j], r[!cur][j]), min(rm[i][j], rm[i - 1][j])) - max(max(l[cur][j], l[!cur][j]), max(lm[i][j], lm[i - 1][j])) + 1) * (dm[i - 1][j] - i + 2));
					}
				}
			}
			cur = !cur;
		}
		printf("%d\n", ans);
	}
	return 0;
}
