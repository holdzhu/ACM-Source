#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

const int mod = 1e8 + 7;
const int N = 360000;
bool b[N];
bool valid[N + 1];
long long pre[N + 1];
vector<int> fac;

int gcd(int a, int b)
{
	return b ? gcd(b, a % b) : a;
}

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

int main()
{
	for (int i = 1; i <= N; ++i)
		if (N % i == 0)
			fac.push_back(i);
	int S, P;
	while (scanf("%d %d", &S, &P) == 2 && S != -1)
	{
		memset(b, 0, sizeof b);
		for (int i = 0; i < P; ++i)
		{
			int A;
			scanf("%d", &A);
			b[A] = true;
		}
		for (int i = 0; i < fac.size(); ++i)
		{
			int j = fac[i];
			if (P % (N / j) == 0)
			{
				valid[j] = true;
				for (int k = 0; k < N; ++k)
					if (b[k] && !b[(k + j) % N])
					{
						valid[j] = false;
						break;
					}
				if (valid[j])
					pre[j] = pow_mod(S, P / (N / j));
			}
			else
				valid[j] = false;
		}
		long long ans = 0;
		long long cnt = 0;
		for (int i = 0; i < N; ++i)
		{
			int g = gcd(i, N);
			if (valid[g])
			{
				ans = (ans + pre[gcd(i, N)]) % mod;
				cnt++;
			}
		}
		ans = ans * pow_mod(cnt, mod - 2) % mod;
		printf("%I64d\n", ans);
	}
	return 0;
}
