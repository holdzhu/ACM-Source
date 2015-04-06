#include <cstdio>
#include <cmath>

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		long long n;
		scanf("%I64d", &n);
		int sqr = sqrt(n);
		long long s = n;
		long long l = n;
		bool flag = false;
		for (int i = 2; i <= sqr; ++i)
		{
			long long t = n / i;
			if (l >= sqr + 1 && sqr + 1 > t)
			{
				flag = true;
			}
			s += (i - 1) * (l - t) + t;
			l = t;
			s %= 1000000;
		}
		if (!flag)
		{
			s += n / (sqr + 1);
			s %= 1000000;
		}
		printf("%I64d\n", s);
	}
	return 0;
}
