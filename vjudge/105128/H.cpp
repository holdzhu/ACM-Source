#include <cstdio>
#include <queue>
#include <algorithm>

using namespace std;

const unsigned K[] = {1, 2, 4, 8};

int stp[256];
unsigned long long ans[256];
unsigned a[9];

void solve(unsigned n)
{
	if (n == 1)
		return;
	solve(n - 1);
	for (int i = 0; i < n - 1; ++i)
		for (int j = 1; j < 4; ++j)
			if (a[i] * K[j] == a[n - 1])
			{
				printf("lea e%cx, [%d*e%cx]\n", n - 1 + 'a', K[j], i + 'a');
				return;
			}
	for (int i = 0; i < n - 1; ++i)
		for (int j = 0; j < n - 1; ++j)
			for (int k = 0; k < 4; ++k)
				if (a[i] + K[k] * a[j] == a[n - 1])
				{
					printf("lea e%cx, [e%cx + %d*e%cx]\n", n - 1 + 'a', i + 'a', K[k], j + 'a');
					return;
				}
}

unsigned nxt[10][255];
void dfs(unsigned long long s, int step)
{
	unsigned long long _s = s;
	int len;
	for (len = 0; s; ++len)
	{
		a[len] = s & 255ull;
		s >>= 8;
		if (stp[a[len]] > step)
        {
            stp[a[len]] = step;
			ans[a[len]] = _s;
        }
	}
	if (step >= 6)
		return;
	int m = 0;
	for (int i = 0; i < len; ++i)
		for (int j = 1; j < 4; ++j)
			if (a[i] * K[j] <= 255u && a[i] * K[j] > a[len - 1])
				nxt[step][m++] = a[i] * K[j];
	for (int i = 0; i < len; ++i)
		for (int j = 0; j < len; ++j)
			for (int k = 0; k < 4; ++k)
				if (a[i] + K[k] * a[j] <= 255u && a[i] + K[k] * a[j] > a[len - 1])
					nxt[step][m++] = a[i] + K[k] * a[j];
	sort(nxt[step], nxt[step] + m);
	m = unique(nxt[step], nxt[step] + m) - nxt[step];
	for (int i = 0; i < m; ++i)
		dfs(_s | ((unsigned long long)nxt[step][i] << (len * 8)), step + 1);
}

int main()
{
	for (int i = 1; i <= 255; ++i)
		stp[i] = 1e9;
	dfs(1, 0);
	int n = 41;
	scanf("%d", &n);
	unsigned long long s = ans[n];
	int len;
	for (len = 0; s; ++len)
	{
		a[len] = s & 255ull;
		s >>= 8;
	}
	printf("%d\n", len - 1);
	solve(len);
	return 0;
}
