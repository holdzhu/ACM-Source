#include <cstdio>
#include <algorithm>

using namespace std;

const int p[] = {2,  3,  5,  7,  11, 13, 17, 19, 23, 29, 31,
				 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 83};

const int maxn = 200000;
int len[maxn + 1];
int pre[maxn + 1];
int ans[1000][1000];
int id = 1;

void solve(int n, int x0, int y0)
{
	if (len[n] * len[n] == n)
	{
		for (int i = 0; i < len[n]; ++i)
			for (int j = 0; j < len[n]; ++j)
				ans[x0 + i][y0 + j] = id++;
	}
	else if (n == 6)
	{
		for (int i = 0; i < 3; ++i)
			ans[x0][y0 + i] = id++;
		for (int i = 1; i < 3; ++i)
			ans[x0 + i][y0] = id++;
		for (int i = 1; i < 3; ++i)
			for (int j = 1; j < 3; ++j)
				ans[x0 + i][y0 + j] = id;
		id++;
	}
	else if (n == 7)
	{
		for (int i = 0; i < 4; i += 2)
			for (int j = 0; j < 4; j += 2)
				ans[x0 + i][y0 + j] = ans[x0 + i][y0 + j + 1]
					= ans[x0 + i + 1][y0 + j] = ans[x0 + i + 1][y0 + j + 1]
					= id++;
		ans[x0][y0] = id++;
		ans[x0 + 1][y0] = id++;
		ans[x0][y0 + 1] = id++;
	}
	else if (n == 8)
	{
		for (int i = 0; i < 4; ++i)
			ans[x0][y0 + i] = id++;
		for (int i = 1; i < 4; ++i)
			ans[x0 + i][y0] = id++;
		for (int i = 1; i < 4; ++i)
			for (int j = 1; j < 4; ++j)
				ans[x0 + i][y0 + j] = id;
		id++;
	}
	else
	{
		int p = len[n] / len[pre[n]];
		int b = (n - p * p) / (pre[n] - 1);
		for (int i = 0; i < p; ++i)
			for (int j = 0; j < p; ++j)
				if (i * p + j < b)
					solve(pre[n], x0 + i * len[pre[n]], y0 + j * len[pre[n]]);
				else
				{
					for (int k = 0; k < len[pre[n]]; ++k)
						for (int l = 0; l < len[pre[n]]; ++l)
							ans[x0 + i * len[pre[n]] + k][y0 + j * len[pre[n]] + l] = id;
					id++;
				}
	}
}

int main()
{
	for (int i = 1; i <= maxn; ++i)
		len[i] = 1e9;
	len[1] = 1;
	len[6] = 3;
	len[7] = len[8] = 4;
	for (int i = 1; i <= maxn; ++i)
		if (len[i] != 1e9)
			for (int k = 0; k < sizeof(p) / sizeof(int); ++k)
				for (int j = 1;
					 j <= p[k] * p[k] && i * j + p[k] * p[k] - j <= maxn; ++j)
					if (len[i * j + p[k] * p[k] - j] > len[i] * p[k])
					{
						len[i * j + p[k] * p[k] - j] = len[i] * p[k];
						pre[i * j + p[k] * p[k] - j] = i;
					}
	int n;
	scanf("%d", &n);
	if (n == 2 || n == 3 || n == 5)
		puts("Impossible");
	else
	{
		printf("Possible\n%d\n", len[n]);
		solve(n, 0, 0);
		for (int i = 0; i < len[n]; ++i)
			for (int j = 0; j < len[n]; ++j)
				printf("%d%c", ans[i][j], j == len[n] - 1 ? '\n' : ' ');
	}
	return 0;
}