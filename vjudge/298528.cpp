#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int gcd(int a, int b)
{
	return b ? gcd(b, a % b) : a;
}

long long lcm(int a, int b)
{
	return 1ll * a / gcd(a, b) * b;
}

const int mod = 1e9 + 7;
const int maxn = 1e6;
int phi[maxn + 1];
inline void phi_table()
{
	phi[1] = 1;
	for (int i = 2; i <= maxn; ++i) if (!phi[i])
		for (int j = i; j <= maxn; j += i)
		{
			if (!phi[j]) phi[j] = j;
			phi[j] = phi[j] / i * (i - 1);
		}
}

inline void factor(int x, vector<int>& fac)
{
	for (int i = 1; i * i <= x; ++i)
		if (x % i == 0)
		{
			fac.push_back(i);
			if (i * i != x)
				fac.push_back(x / i);
		}
}

inline long long pow_mod(long long a, long long k)
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

const int maxk = 10000;
int p[maxk];
int cnt[maxk + 1];

int main()
{
	phi_table();
	int T;
	scanf("%d", &T);
	for (int kase = 1; kase <= T; ++kase)
	{
		int K, R, C;
		scanf("%d %d %d", &K, &R, &C);
		vector<int> facR, facC;
		factor(R, facR);
		factor(C, facC);
		for (int i = 0; i < K; ++i)
			scanf("%d", &p[i]);
		for (int i = 1; i <= maxk; ++i)
			cnt[i] = 0;
		for (int i = 0; i < K; ++i)
			if (p[i] != -1)
			{
				int c = 0;
				int u = i;
				do
				{
					int v = p[u];
					p[u] = -1;
					u = v;
					c++;
				}
				while (u != i);
				cnt[c]++;
			}
		vector<pair<int, int> > perm;
		for (int i = 1; i <= maxk; ++i)
			if (cnt[i] && 1ll * R * C % i == 0)
				perm.push_back(make_pair(i, cnt[i] * i));
		long long ans = 0;
		for (int i = 0; i < facR.size(); ++i)
			for (int j = 0; j < facC.size(); ++j)
			{
				int a = facR[i];
				int b = facC[j];
				long long l = lcm(a, b);
				int tmp = 0;
				for (int k = 0; k < perm.size() && perm[k].first <= l; ++k)
					if (l % perm[k].first == 0)
						tmp += perm[k].second;
				ans = (ans + 1ll * phi[a] * phi[b] % mod * pow_mod(tmp % mod, 1ll * R * C / l) % mod) % mod;
			}
		printf("Case #%d: %lld\n", kase, ans * pow_mod(1ll * R * C % mod, mod - 2) % mod);
	}
	return 0;
}
