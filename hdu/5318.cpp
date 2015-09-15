#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int n, m;
const int mod = 1000000007;
int a[50];
char s[50][11];
long long d[50][50];

bool check(char* a, char* b)
{
	int la = strlen(a);
	int lb = strlen(b);
	int l = min(la, lb);
	for (int i = l; i > 1; --i)
	{
		bool flag = true;
		for (int j = 0; j < i; ++j)
		{
			if (a[la - i + j] != b[j])
			{
				flag = false;
				break;
			}
		}
		if (flag)
		{
			return true;
		}
	}
	return false;
}

long long p[50][50];
long long tmp[50][50];
long long g[50][50];

int solve()
{
	if (m == 1)
	{
		return n;
	}
	m--;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			p[i][j] = i == j;
		}
	}
	memcpy(g, d, sizeof g);
	while (m)
	{
		if (m & 1)
		{
			for (int i = 0; i < n; ++i)
			{
				for (int j = 0; j < n; ++j)
				{
					tmp[i][j] = 0;
					for (int k = 0; k < n; ++k)
					{
						tmp[i][j] = (tmp[i][j] + p[i][k] * g[k][j] % mod) % mod;
					}
				}
			}
			memcpy(p, tmp, sizeof p);
		}
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				tmp[i][j] = 0;
				for (int k = 0; k < n; ++k)
				{
					tmp[i][j] = (tmp[i][j] + g[i][k] * g[k][j] % mod) % mod;
				}
			}
		}
		memcpy(g, tmp, sizeof g);
		m >>= 1;
	}
	long long rnt = 0;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			rnt = (rnt + p[i][j]) % mod;
		}
	}
	return rnt;
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d %d", &n, &m);
		for (int i = 0; i < n; ++i)
		{
			scanf("%d", &a[i]);
		}
		sort(a, a + n);
		n = unique(a, a + n) - a;
		for (int i = 0; i < n; ++i)
		{
			sprintf(s[i], "%d", a[i]);
		}
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				d[i][j] = check(s[i], s[j]);
			}
		}
		printf("%d\n", solve());
	}
	return 0;
}
