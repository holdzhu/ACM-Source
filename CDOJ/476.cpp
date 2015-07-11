#include <cstdio>
#include <cmath>

int gcd(int a, int b)
{
	return !b ? a : gcd(b, a % b);
}

int phi(int x)
{
	int res = x;
	int sqr = sqrt(x + 0.5);
	for (int i = 2; i <= sqr && x > 1; ++i)
	{
		if (x % i == 0)
		{
			res = res / i * (i - 1);
			while (x % i == 0)
			{
				x /= i;
			}
		}
	}
	if (x > 1)
	{
		res = res / x * (x - 1);
	}
	return res;
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int N, M;
		scanf("%d %d", &N, &M);
		int sqr = sqrt(N + 0.5);
		int cnt = 0;
		for (int i = 1; i < sqr; ++i)
		{
			if (N % i == 0)
			{
				if (i >= M)
				{
					cnt += phi(N / i);
				}
				if (N / i >= M)
				{
					cnt += phi(i);
				}
			}
		}
		if (sqr * sqr == N && sqr >= M)
		{
			cnt += phi(sqr);
		}
		printf("%d\n", cnt);
	}
	return 0;
}
