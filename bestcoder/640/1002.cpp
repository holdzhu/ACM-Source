#include <cstdio>
#include <algorithm>

using namespace std;

struct Problem
{
	long long A, B, C;
	bool operator < (const Problem& rhs) const
	{
		return B * rhs.C > C * rhs.B;
	}
};

long long dp[3001];
Problem pro[1000];

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int n, t;
		scanf("%d %d", &n, &t);
		for (int i = 0; i < n; ++i)
		{
			scanf("%I64d %I64d %I64d", &pro[i].A, &pro[i].B, &pro[i].C);
		}
		for (int i = 0; i <= t; ++i)
		{
			dp[i] = 0;
		}
		sort(pro, pro + n);
		long long ans = 0;
		for (int i = 0; i < n; ++i)
		{
			for (int j = t; j >= pro[i].C; --j)
			{
				dp[j] = max(dp[j], dp[j - pro[i].C] + pro[i].A - pro[i].B * j);
				ans = max(ans, dp[j]);
			}
		}
		printf("%I64d\n", ans);
	}
	return 0;
}
