#include <cstdio>

long long C(long long x, long long y)
{
	long long ans = 1;
	for (int i = 1; i <= x; ++i)
	{
		ans *= y - i + 1;
		ans /= i;
	}
	return ans;
}

int F(long long x,long long y)
{
    int tot=0;
    while(x%y==0)
    {
       tot++;
       x=x/y;
    }
    return tot;
}

int main()
{
	long long t, m;
	// scanf("%lld %lld", &t, &m);
	t = 7;
	for (m = t; m < 50; m += t)
	{
		long long s = 1;
		while (s * t < m)
		{
			s *= t;
		}
		long long s2 = s;
		while (s2 + s <= m)
		{
			s2 += s;
		}
		long long max = 0;
		long long maxc = -1;
		for (int i = 0; i <= m; ++i)
		{
			if (F(C(i, m), t) >= max)
			{
				max = F(C(i, m), t);
				maxc = i;
			}
		}
		printf("%lld %lld %lld %lld\n", m, t, s2 - 1, maxc);
	}
	return 0;
}
