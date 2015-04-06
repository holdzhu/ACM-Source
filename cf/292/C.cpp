#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int d[100000];
int s[100001];
int h[100000];
int dp1[100000][20];
int dp2[100000][20];
int n, m;

int RMQ(int L, int R)
{
	int k = 0;
	while ((1 << (k + 1)) <= R - L + 1)
	{
		k++;
	}
	return max(dp1[L][k], dp1[R - (1 << k) + 1][k]) + max(dp2[L][k], dp2[R - (1 << k) + 1][k]) - s[n];
}

int main()
{
	scanf("%d %d", &n, &m);
	s[0] = 0;
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &d[i]);
		s[i + 1] = s[i] + d[i];
	}
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &h[i]);
	}
	for (int i = 0; i < n; ++i)
	{
		dp1[i][0] = s[i] + h[i] * 2;
		printf("%d\n", dp1[i][0]);
	}
	for (int j = 1; (1 << j) <= n; ++j)
	{
		for (int i = 0; i + (1 << j) - 1 < n; ++i)
		{
			dp1[i][j] = max(dp1[i][j - 1], dp1[i + (1 << (j - 1))][j - 1]);
		}
	}
	for (int i = 0; i < n; ++i)
	{
		dp2[i][0] = s[n] - s[i + 1] + h[i] * 2;
		printf("%d\n", dp2[i][0]);
	}
	for (int j = 1; (1 << j) <= n; ++j)
	{
		for (int i = 0; i + (1 << j) - 1 < n; ++i)
		{
			dp2[i][j] = max(dp2[i][j - 1], dp2[i + (1 << (j - 1))][j - 1]);
		}
	}
	while (m--)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		if (a <= b)
		{
			printf("%d %d\n", RMQ(0, a - 2), RMQ(b, n));
		}
	}
	return 0;
}
