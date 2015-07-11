#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>

using namespace std;

vector<int> pm;
int tim[32];
long long num;

int gcd(int a, int b)
{
	return b ? gcd(b, a % b) : a;
}

int exgcd(int a, int b, int& x, int& y)
{
	if (b)
	{
		int d = exgcd(b, a % b, y, x);
		y -= x * (a / b);
		return d;
	}
	x = 1;
	y = 0;
	return a;
}

int inv(int a, int mod)
{
	int x, y;
	exgcd(a, mod, x, y);
	return ((x % mod) + mod) % mod;
}

int main()
{
	int n, m;
	while (scanf("%d %d", &n, &m) == 2 && n && m)
	{
		int t = m;
		int sqr = sqrt(m);
		for (int i = 2; i <= sqr && t > 1; ++i)
		{
			if (t % i == 0)
			{
				while (t % i == 0)
				{
					t /= i;
				}
				pm.push_back(i);
			}
		}
		if (t > 1)
		{
			pm.push_back(t);
		}
		long long sum = 0;
		num = 1;
		memset(tim, 0, sizeof tim);
		for (int i = 0; i < n; ++i)
		{
			int M = 2 * (2 * i + 1);
			int D = i + 2;
			for (int i = 0; i < pm.size() && M > 1; ++i)
			{
				while (M % pm[i] == 0)
				{
					M /= pm[i];
					tim[i]++;
				}
			}
			num = num * M % m;
			for (int i = 0; i < pm.size() && D > 1; ++i)
			{
				while (D % pm[i] == 0)
				{
					D /= pm[i];
					tim[i]--;
				}
			}
			num = num * inv(D, m) % m;
			long long tmp = num;
			for (int i = 0; i < pm.size(); ++i)
			{
				for (int j = 0; j < tim[i]; ++j)
				{
					tmp = tmp * pm[i] % m;
				}
			}
			sum = (sum + tmp) % m;
		}
		printf("%lld\n", sum);
	}
	return 0;
}
