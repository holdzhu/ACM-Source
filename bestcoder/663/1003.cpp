#include <cstdio>
#include <vector>
#include <unordered_map>

using namespace std;

const int mod = 1e9 + 7;
const int inv3 = (mod + 1) / 3;
const int maxn = 3e5;
unordered_map<int, long long> dp;
vector<int> fac[maxn + 1];
long long sum[maxn + 1];

long long solve(long long n)
{
	if (n <= maxn)
	{
		return sum[n];
	}
	if (dp.count(n)) return dp[n];
	long long s = n * (n - 1) % mod * (n - 2) % mod * inv3 % mod;
	for (int i = 1; i * i <= n; ++i)
	{
		if (i > 1) s = (s - solve(n / i)) % mod;
		s = (s - solve(i) * (n / i - n / (i + 1) - (n / i == i)) % mod) % mod;
	}
	if (s < 0)
	{
		s += mod;
	}
	return dp[n] = s;
}

int main()
{
	int T;
	scanf("%d", &T);
	for (int i = 1; i <= maxn; ++i)
	{
		for (int j = i + i; j <= maxn; j += i)
		{
			fac[j].push_back(i);
		}
	}
	for (int i = 1; i <= maxn; ++i)
	{
		sum[i] = 1ll * (i - 1) * (i - 2);
		for (int j = 0; j < fac[i].size(); ++j)
		{
			sum[i] = (sum[i] - sum[fac[i][j]]) % mod;
		}
		if (sum[i] < 0)
		{
			sum[i] += mod;
		}
	}
	for (int i = 2; i <= maxn; ++i)
	{
		sum[i] += sum[i - 1];
	}
	while (T--)
	{
		int n;
		scanf("%d", &n);
		printf("%d\n", (int)solve(n));
	}
	return 0;
}
