#include <cstdio>
#include <cstring>

const int mod = 1000000007;
long long catalan[501][501];
int p[500];
int l[500];
int r[500];
int t[500];
int color[500];
int colorcnt[500];
int colorreduce[500];
int sz;

void calcCatalan()
{
	for (int i = 0; i < 500; ++i)
	{
		catalan[0][i] = 1;
	}
	catalan[1][0] = catalan[1][1] = 1;
	for (int i = 2; i <= 500; ++i)
	{
		catalan[1][i] = 0;
		for (int j = 0; j < i; ++j)
		{
			catalan[1][i] = (catalan[1][i] + catalan[1][j] * catalan[1][i - j - 1]) % mod;
		}
	}
	for (int i = 2; i <= 500; ++i)
	{
		catalan[i][0] = 1;
		for (int j = 1; j <= 500; ++j)
		{
			catalan[i][j] = 0;
			for (int k = 0; k <= j; ++k)
			{
				catalan[i][j] = (catalan[i][j] + catalan[i - 1][k] * catalan[1][j - k]) % mod;
			}
		}
	}
}

bool build()
{
	memset(p, -1, sizeof p);
	memset(l, -1, sizeof l);
	memset(r, -1, sizeof r);
	memset(color, -1, sizeof color);
	memset(colorreduce, 0, sizeof colorreduce);
	memset(t, 0, sizeof t);
	int n;
	if (scanf("%d", &n) != 1)
	{
		return false;
	}
	int pos = 0;
	color[0] = 0;
	int curcolor = 0;
	sz = 1;
	while (n--)
	{
		int cmd;
		scanf("%d", &cmd);
		if (cmd == 0)
		{
			pos = p[pos];
		}
		else if (cmd == 1)
		{
			if (l[pos] != -1)
			{
				pos = l[pos];
			}
			else
			{
				l[pos] = sz;
				p[sz++] = pos;
				pos = l[pos];
			}
		}
		else if (cmd == 2)
		{
			if (r[pos] != -1)
			{
				pos = r[pos];
			}
			else
			{
				r[pos] = sz;
				p[sz++] = pos;
				pos = r[pos];
			}
		}
		else if (cmd == 3)
		{
			l[pos] = sz;
			p[sz] = pos;
			color[sz] = sz;
			colorreduce[curcolor]++;
			scanf("%d", &t[sz++]);
		}
		else if (cmd == 4)
		{
			r[pos] = sz;
			p[sz] = pos;
			color[sz] = sz;
			colorreduce[curcolor]++;
			scanf("%d", &t[sz++]);
		}
		if (color[pos] != -1)
		{
			curcolor = color[pos];
		}
		else
		{
			color[pos] = curcolor;
		}
	}
	return true;
}

int solve()
{
	memset(colorcnt, 0, sizeof colorcnt);
	for (int i = 0; i < sz; ++i)
	{
		if (color[i] > 0)
		{
			colorcnt[color[i]]++;
		}
	}
	long long ans = 1;
	for (int i = 1; i < sz; ++i)
	{
		if (t[i])
		{
			ans = (ans * catalan[colorcnt[i] + 1 - colorreduce[i]][t[i] - colorcnt[i]]) % mod;
		}
	}
	return ans;
}

int main()
{
	calcCatalan();
	for (int kase = 1; build(); ++kase)
	{
		printf("Case #%d: %d\n", kase, solve());
	}
	return 0;
}
