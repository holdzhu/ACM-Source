#include <cstdio>
#include <cstring>
#include <climits>
#include <algorithm>

using namespace std;

int h[100001];
int dp[100001];
int p[100000];
bool first;

bool cmp(const int& a, const int& b)
{
	return h[a] < h[b];
}

void print(int x)
{
	if (x != -1)
	{
		print(p[x]);
		if (first)
		{
			first = false;
		}
		else
		{
			printf(" ");
		}
		printf("%d", h[x]);
	}
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int n;
		scanf("%d", &n);
		for (int i = 0; i <= n; ++i)
		{
			dp[i] = n;
		}
		h[n] = INT_MAX;
		for (int i = 0; i < n; ++i)
		{
			scanf("%d", &h[i]);
			int pt = lower_bound(dp, dp + n + 2, i, cmp) - dp;
			p[i] = pt == 0 ? -1 : dp[pt - 1];
			dp[pt] = i;
		}
		for (int i = 0; i <= n; ++i)
		{
			if (h[dp[i]] == INT_MAX)
			{
				printf("%d\n", i);
				first = true;
				print(dp[i - 1]);
				printf("\n");
				break;
			}
		}
	}
	return 0;
}
