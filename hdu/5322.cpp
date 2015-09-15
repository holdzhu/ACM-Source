#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 100001;
const int mod = 998244353;
const int Mod = 998244353;

int powmod(long long x, int n)
{
	long long rnt = 1;
	while (n)
	{
		if (n & 1)
		{
			rnt *= x;
			rnt %= mod;
		}
		x *= x;
		x %= mod;
		n >>= 1;
	}
	return rnt;
}

int Top, m1[N << 3], m2[N << 3];

void NTT(int *a, int n, int rev)
{
	for (int i = 1, j = 0; i < n; ++i)
	{
		for (int k = n >> 1; k > (j ^= k); k >>= 1);
		if (i < j)
		{
			swap(a[i], a[j]);
		}
	}
	for (int i = 0; i < n; ++i)
	{
		m2[i] = m1[i * (Top / n)];
	}
	for (int m = 2; m <= n; m <<= 1)
	{
		int wm = rev == 1 ? n - n / m : n / m;
		for (int i = 0; i < n; i += m)
		{
			int w = 0;
			for (int j = i; j < i + m / 2; ++j)
			{
				int t = 1ll * m2[w] * a[j + m / 2] % mod;
				a[j + m / 2] = a[j] - t;
				if (a[j + m / 2] < 0)
				{
					a[j + m / 2] += mod;
				}
				a[j] = a[j] + t;
				if (a[j] >= mod)
				{
					a[j] -= mod;
				}
				w += wm;
				if (w >= n)
				{
					w -= n;
				}
			}
		}
	}
	if (rev == -1)
	{
		int inv = powmod(n, mod - 2);
		for (int i = 0; i < n; ++i)
		{
			a[i] = 1ll * a[i] * inv % mod;
		}
	}
}

int dp[N], a[N << 3], b[N << 3];
int fac[N], ff[N];

void solve(int l, int r)
{
	if (l == r)
	{
		return;
	}
	int mid = (l + r) >> 1;
	solve(l, mid);
	int len = r - l + 1;
	int n = 1;
	while (n <= len * 2)
	{
		n <<= 1;
	}
	for (int i = 0; i < n; ++i)
	{
		a[i] = b[i] = 0;
	}
	for (int i = l; i <= mid; ++i)
	{
		a[i - l + 1] = 1ll * dp[i] * ff[i] % mod;
	}
	for (int i = 1; i <= len; ++i)
	{
		b[i] = 1ll * i * i % mod;
	}
	NTT(a, n, 1);
	NTT(b, n, 1);
	for (int i = 0; i < n; ++i)
	{
		a[i] = 1ll * a[i] * b[i] % mod;
	}
	NTT(a, n, -1);
	for (int i = mid + 1; i <= r; ++i)
	{
		dp[i] = (dp[i] + 1ll * a[i - l + 1] * fac[i - 1] % mod) % mod;
	}
	solve(mid + 1, r);
}

void init(int n)
{
	fac[0] = ff[0] = 1;
	for (int i = 1; i <= n; ++i)
	{
		fac[i] = 1ll * fac[i - 1] * i % mod;
		ff[i] = powmod(fac[i], mod - 2);
	}
	int maxn = 1;
	while (maxn <= 2 * n)
	{
		maxn <<= 1;
	}
	Top = maxn;
	m1[0] = 1;
	m1[1] = powmod(3, (mod - 1) / Top);
	for (int i = 2; i < Top; ++i)
	{
		m1[i] = 1ll * m1[i - 1] * m1[1] % mod;
	}
	dp[0] = 1;
	solve(0, n);
}

int main()
{
	init(100000);
	int n;
	while (scanf("%d", &n) == 1)
	{
		printf("%d\n", dp[n]);
	}
	return 0;
}
