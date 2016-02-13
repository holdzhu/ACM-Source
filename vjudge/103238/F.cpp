#include <cstdio>
#include <vector>

using namespace std;

const int mod = 1e9 + 7;

long long pow_mod(long long a, long long k)
{
	long long s = 1;
	while (k)
	{
		if (k & 1)
			s = s * a % mod;
		a = a * a % mod;
		k >>= 1;
	}
	return s;
}

int N, K;

long long solve(int n)
{
	return (pow_mod(K - 2, n) + (n & 1 ? -1 : 1) * (K - 2)) % mod;
}

vector<pair<int, int> > fac;
long long ans;

void dfs(int i, int n, int phi)
{
	if (i == fac.size())
	{
		ans = (ans + phi * solve(N / n) % mod) % mod;
	}
	else
	{
		dfs(i + 1, n, phi);
		phi *= fac[i].first - 1;
		for (int j = 0; j < fac[i].second; ++j)
		{
			dfs(i + 1, n *= fac[i].first, phi);
			phi *= fac[i].first;
		}
	}
}

int main()
{
	while (scanf("%d %d", &N, &K) == 2)
	{
		fac.clear();
		int n = N;
		for (int i = 2; i * i <= n; ++i)
		{
			if (n % i == 0)
			{
				fac.push_back(make_pair(i, 0));
				while (n % i == 0)
				{
					fac.back().second++;
					n /= i;
				}
			}
		}
		if (n > 1)
			fac.push_back(make_pair(n, 1));
		ans = 0;
		dfs(0, 1, 1);
		ans = ans * pow_mod(N, mod - 2) % mod * K % mod;
		if (ans < 0)
			ans += mod;
		printf("%I64d\n", ans);
	}
	return 0;
}
