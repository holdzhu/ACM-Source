#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int n, m;
char s[1501], t[3001];
int h[1501][3001], v[1501][3001];
int ans = 0;

void solve()
{
	for (int i = 0; i < m; ++i)
	{
		h[0][i] = i + 1;
	}
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (s[i] == t[j])
			{
				h[i + 1][j] = v[i][j];
				v[i][j + 1] = h[i][j];
			}
			else
			{
				h[i + 1][j] = max(h[i][j], v[i][j]);
				v[i][j + 1] = min(h[i][j], v[i][j]);
			}
		}
	}
	// for (int i = 0; i <= n; ++i)
	// {
	// 	for (int j = 0; j < m; ++j)
	// 	{
	// 		printf("%d ", h[i][j]);
	// 	}
	// 	printf("\n");
	// }
	for (int i = 0; i < m; ++i)
	{
		printf("%c\n", t[i]);
		int sum = 0;
		for (int j = i; j < m; ++j)
		{
			if (h[n][j] <= i)
			{
				sum++;
				printf("%c", t[j]);
			}
			if (j - i + 1 == m / 2)
			{
				break;
			}
		}
		puts("");
	}
}

int main()
{
	scanf("%s %s", s, t);
	n = strlen(s);
	m = strlen(t);
	memcpy(t + m, t, m);
	m *= 2;
	solve();
	for (int i = 0; i < m / 2; ++i)
	{
		swap(t[i], t[m - 1 - i]);
	}
	solve();
	printf("%d\n", ans * 2);
	return 0;
}
