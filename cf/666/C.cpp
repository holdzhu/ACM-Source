#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

const int mod = 1e9 + 7;
const int len = 320;

struct Query
{
	int l, r, id;
	bool operator<(const Query &rhs) const
	{
		return r / len < rhs.r / len || (r / len == rhs.r / len && l > rhs.l);
	}
};

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

const int maxn = 1e5 + 10;

long long inv25, inv26;
Query q[100100];
int res[100100];
int n = 0;
char s[100100];
long long fac[100100];
long long inv[100100];
long long facinv[100100];
long long pow26[100100];
long long pow25[100100];

long long C(int n, int m)
{
	if (n < 0 || m < 0 || m > n)
		return 0;
	return fac[n] * facinv[m] % mod * facinv[n - m] % mod;
}

void init()
{
	inv25 = pow_mod(25, mod - 2);
	inv26 = pow_mod(26, mod - 2);
	fac[0] = fac[1] = inv[1] = facinv[0] = facinv[1] = 1;
	for (int i = 2; i <= maxn; ++i)
	{
		fac[i] = fac[i - 1] * i % mod;
		inv[i] = inv[mod % i] * (mod - mod / i) % mod;
		facinv[i] = facinv[i - 1] * inv[i] % mod;
	}
	pow26[0] = pow25[0] = 1;
	for (int i = 1; i <= maxn; ++i)
	{
		pow26[i] = pow26[i - 1] * 26 % mod;
		pow25[i] = pow25[i - 1] * 25 % mod;
	}
}

int main()
{
	init();
	int m;
	scanf("%d", &m);
	scanf("%s", s);
	int l = strlen(s);
	while (m--)
	{
		int t;
		scanf("%d", &t);
		if (t == 1)
		{
			scanf("%s", s);
			l = strlen(s);
		}
		else
		{
			int r;
			scanf("%d", &r);
			q[n] = {l, r, n};
			++n;
		}
	}
	sort(q, q + n);
	int L = 1, R = 1;
	long long ans = 1;
	for (int i = 0; i < n; ++i)
	{
		if (i == 0 || q[i].r / len != q[i - 1].r / len)
		{
			L = maxn;
			R = q[i].r;
			ans = 0;
		}
		while (L > q[i].l)
		{
			--L;
			if (R >= L)
			{
				long long t1 = ans * 26 % mod;
				long long t2 = ans * 25 % mod;
				ans = (t1 - t2 + mod) % mod;
				ans = (ans + pow25[R - L] * C(R - 1, L) % mod) % mod;
				ans = (ans + pow25[R - L] * C(R - 1, L - 1) % mod) % mod;
			}
		}
		while (R < q[i].r)
		{
			++R;
			ans = ans * 26 % mod;
			if (R >= L)
			{
				ans += pow25[R - L] * C(R - 1, L - 1) % mod;
				if (ans >= mod)
					ans -= mod;
			}
		}
		while (R > q[i].r)
		{
			if (R >= L)
			{
				ans -= pow25[R - L] * C(R - 1, L - 1) % mod;
				if (ans < 0)
					ans += mod;
			}
			ans = ans * inv26 % mod;
			--R;
		}
		res[q[i].id] = ans;
	}
	for (int i = 0; i < n; ++i)
		printf("%d\n", res[i]);
	return 0;
}
