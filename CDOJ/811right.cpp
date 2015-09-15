#include <cstdio>
#include <cmath>

const int mod = 1000000007;
const int maxn = 10000000;
long long N;
int K;
int inv;

int get_inv(long long a)
{
	long long ans = 1;
	int p = mod - 2;
	while (p)
	{
		if (p & 1)
		{
			ans = ans * a % mod;
		}
		p >>= 1;
		a = a * a % mod;
	}
	return ans;
}

int phi[maxn];
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
			for (int j = i; j <= n; j += i)
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

long long euler_phi(long long n)
{
	if (n <= maxn)
	{
		return phi[n];
	}
	int m = (int)sqrt(n + 0.5);
	long long ans = n;
	for (int i = 2; i <= m && n > 1; ++i)
	{
		if (n % i == 0)
		{
			ans = ans / i * (i - 1);
			while (n % i == 0)
			{
				n /= i;
			}
		}
	}
	if (n > 1)
	{
		ans = ans / n * (n - 1);
	}
	return ans % mod;
}

long long sum(long long r, int K)
{
	r %= mod;
	long long rnt = 0;
	if (K == 1 || K == 3)
	{
		rnt = r * (r + 1) % mod * inv % mod;
		if (K == 3)
		{
			rnt = rnt * rnt % mod;
		}
	}
	else if (K == 2)
	{
		rnt = r * (r + 1) % mod * (r * 2 + 1) % mod * inv % mod;
	}
	else if (K == 4)
	{
		rnt = r * (r + 1) % mod * (r * 2 + 1) % mod * (r * r * 3 % mod + r * 3 % mod - 1) % mod * inv % mod;
	}
	else if (K == 5)
	{
		rnt = r * r % mod * (r + 1) % mod * (r + 1) % mod * (r * r * 2 % mod + r * 2 % mod - 1) % mod * inv % mod;
	}
	return rnt;
}

long long pow_mod(long long a, int p)
{
	while (--p)
	{
		a = a * a % mod;
	}
	return a;
}

int main()
{
	phi_table(maxn);
	scanf("%lld %d", &N, &K);
	if (K == 1 || K == 3)
	{
		inv = get_inv(2);
	}
	else if (K == 2)
	{
		inv = get_inv(6);
	}
	else if (K == 4)
	{
		inv = get_inv(30);
	}
	else if (K == 5)
	{
		inv = get_inv(12);
	}
	long long ans = 0;
	for (int i = 1, j = N; i <= j; ++i, j = N / i)
	{
		printf("%lld %lld\n", pow_mod(i, K), euler_phi(N / i));
		ans = (ans + pow_mod(i, K) * euler_phi(N / i) % mod) % mod;
		ans = (ans + (sum(j, K) - sum(N / (i + 1), K)) * euler_phi(i) % mod) % mod;
	}
	if (ans < 0)
	{
		ans += mod;
	}
	printf("%lld\n", ans);
	return 0;
}
