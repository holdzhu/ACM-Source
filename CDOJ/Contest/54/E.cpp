#include <cstdio>
#include <cmath>

long long phi[1000001];
void phi_table(int n)
{
	for (int i = 2; i <= n; ++i)
	{
		phi[i] = 0;
	}
	phi[1] = 1;
	for (int i = 2; i <= n; ++i)
	{
		if (!phi[i])
		{
			for (int j = 0; j <= n; j += i)
			{
				if (!phi[j])
				{
					phi[j] = j;
				}
				phi[j] = phi[j] / i * (i - 1);
			}
		}
	}
}

long long phis[1000001];

int main()
{
	int T;
	scanf("%d", &T);
	phi_table(1000000);
	phis[0] = 0;
	for (int i = 1; i <= 1000000; ++i)
	{
		phis[i] = phis[i - 1] + phi[i];
	}
	while (T--)
	{
		long long m, n;
		scanf("%lld %lld", &m, &n);
		long long ans = 0;
		long long ans2 = 0;
		int sq = sqrt(n + 0.5);
		long long r = n;
		for (int i = 1; i <= sq && i < m; ++i)
		{
			ans += n / i * phi[i];
			long long l = n / i;
			if (l < m && r < m)
			{
				ans += (i - 1) * (phis[r] - phis[l]);
			}
			else if (l < m && r >= m)
			{
				ans += (i - 1) * (phis[m - 1] - phis[l]);
			}
			// printf("%d %lld %lld\n", i, l, r);
			r = l;
		}
		long long l = sq;
		if (l < m && r < m)
		{
			ans += sq * (phis[r] - phis[l]);
		}
		else if (l < m && r >= m)
		{
			ans += sq * (phis[m - 1] - phis[l]);
		}
		// for (int i = 1; i < m; ++i)
		// {
		// 	ans2 += n / i * phi[i];
		// }
		// printf("%lld %lld\n", ans, ans2);
		printf("%lld\n", n * (n + 1) / 2 - ans);
	}
	return 0;
}
