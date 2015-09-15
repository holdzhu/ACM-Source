#include <cstdio>
#include <map>

using namespace std;

map<long long, long long> dp[2];

int main()
{
	int n, k;
	scanf("%d %d", &n, &k);
	long long ans = 0;
	while (n--)
	{
		int t;
		scanf("%d", &t);
		if (t % k == 0)
		{
			ans += dp[1][t / k];
			dp[1][t] += dp[0][t / k];
		}
		dp[0][t]++;
	}
	printf("%I64d\n", ans);
	return 0;
}
