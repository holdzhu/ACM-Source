#include <cstdio>
#include <cstring>
#include <cmath>
#include <climits>
#include <algorithm>

using namespace std;

struct Num
{
	long long val;
	int p;
	bool operator < (const Num& rhs) const
	{
		return val < rhs.val || (val == rhs.val && p < rhs.p);
	}
};

int N;
int n, m;
long long add[1000];
Num a[1000][1000];

int bmin(int x, long long y)
{
	int L = 0;
	int R = m - 1;
	while (R > L)
	{
		int M = (L + R) >> 1;
		if (a[x][M].val < y)
		{
			L = M + 1;
		}
		else
		{
			R = M;
		}
	}
	if (a[x][L].val == y)
	{
		return x * m + a[x][L].p;
	}
	else
	{
		return N;
	}
}

int bmax(int x, long long y)
{
	int L = 0;
	int R = m - 1;
	while (R > L)
	{
		int M = (L + R + 1) >> 1;
		if (a[x][M].val > y)
		{
			R = M - 1;
		}
		else
		{
			L = M;
		}
	}
	if (a[x][L].val == y)
	{
		return x * m + a[x][L].p;
	}
	else
	{
		return -1;
	}
}

int main()
{
	int q;
	scanf("%d %d", &N, &q);
	n = sqrt(N + 0.5);
	m = (N + n - 1) / n;
	memset(a, 0, sizeof a);
	memset(add, 0, sizeof add);
	for (int i = 0; i < N; ++i)
	{
		scanf("%I64d", &a[i / m][i % m].val);
	}
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			a[i][j].p = j;
			if (i * m + j >= N)
			{
				a[i][j].val = LLONG_MIN;
			}
		}
		sort(a[i], a[i] + m);
	}
	while (q--)
	{
		int st;
		scanf("%d", &st);
		if (st == 1)
		{
			int l, r, x;
			scanf("%d %d %d", &l, &r, &x);
			l--;
			r--;
			int lx = l / m;
			int ly = l % m;
			int rx = r / m;
			int ry = r % m;
			if (lx == rx)
			{
				for (int i = 0; i < m; ++i)
				{
					if (a[lx][i].p >= ly && a[lx][i].p <= ry)
					{
						a[lx][i].val += x;
					}
				}
				sort(a[lx], a[lx] + m);
			}
			else
			{
				for (int i = 0; i < m; ++i)
				{
					if (a[lx][i].p >= ly)
					{
						a[lx][i].val += x;
					}
				}
				sort(a[lx], a[lx] + m);
				for (int i = 0; i < m; ++i)
				{
					if (a[rx][i].p <= ry)
					{
						a[rx][i].val += x;
					}
				}
				sort(a[rx], a[rx] + m);
				for (int i = lx + 1; i <= rx - 1; ++i)
				{
					add[i] += x;
				}
			}
		}
		else
		{
			int y;
			scanf("%d", &y);
			int mini = N;
			int maxi = -1;
			for (int i = 0; i < n; ++i)
			{
				mini = min(mini, bmin(i, y - add[i]));
				maxi = max(maxi, bmax(i, y - add[i]));
			}
			if (mini == N)
			{
				printf("-1\n");
			}
			else
			{
				printf("%d\n", maxi - mini);
			}
		}
	}
	return 0;
}
