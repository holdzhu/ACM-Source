#include <cstdio>
#include <algorithm>

using namespace std;

const int mod = 1e9 + 7;
const int inv4 = (mod + 1) / 4;

int A, C;
pair<int, int> p[200];
int d[200];
int cnt;
long long tmp;
long long ans;
long long K;
long long D;

long long pow_mod(long long a, long long k)
{
	long long s = 1;
	a %= mod;
	while (k)
	{
		if (k & 1)
			s = s * a % mod;
		a = a * a % mod;
		k >>= 1;
	}
	return s;
}

void dfs2(int i, long long n, long long phi)
{
	if (i == cnt)
		tmp = (tmp + phi % mod * pow_mod(K, D / n) % mod) % mod;
	else
	{
		dfs2(i + 1, n, phi);
		phi *= p[i].first - 1;
		for (int j = 0; j < p[i].second - d[i]; ++j)
			dfs2(i + 1, n *= p[i].first, phi), phi *= p[i].first;
	}
}

void dfs1(int i, int n)
{
	if (i == cnt)
	{
		if (n & 1)
			K = (pow_mod(C, 1ll * n * n - 1)
				+ pow_mod(C, (1ll * n * n - 1) / 2)
				+ pow_mod(C, (1ll * n * n - 1) / 4) * 2) % mod * inv4 % mod * C % mod;
		else
			K = (pow_mod(C, 1ll * n * n)
				+ pow_mod(C, 1ll * n * n / 2)
				+ pow_mod(C, 1ll * n * n / 4) * 2) % mod * inv4 % mod;
		D = (1ll * A * A - 1) / n / n;
		tmp = 0;
		dfs2(0, 1, 1);
		ans = (ans + tmp * pow_mod(D, mod - 2) % mod) % mod;
	}
	else
		for (d[i] = 0; d[i] <= p[i].second; d[i] += 2, n *= p[i].first)
			dfs1(i + 1, n);
}

void factor(int n)
{
	for (int i = 2; i * i <= n; ++i)
		if (n % i == 0)
		{
			int c = 0;
			while (n % i == 0)
				n /= i, c++;
			p[cnt++] = make_pair(i, c);
		}
	if (n > 1)
		p[cnt++] = make_pair(n, 1);
}

int main()
{
	int T;
	scanf("%d", &T);
	for (int kase = 1; kase <= T; ++kase)
	{
		cnt = 0;
		scanf("%d %d", &A, &C);
		factor(A - 1);
		factor(A + 1);
		sort(p, p + cnt);
		int t = cnt;
		cnt = 1;
		for (int i = 1; i < t; ++i)
		{
			if (p[i].first == p[cnt - 1].first)
				p[cnt - 1].second += p[i].second;
			else
				p[cnt++] = p[i];
		}
		ans = 0;
		dfs1(0, 1);
		ans = ans * C % mod;
		printf("Case %d: %I64d\n", kase, A == 1 ? C : ans);
	}
	return 0;
}
