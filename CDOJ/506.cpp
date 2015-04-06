#include <cstdio>

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		long long a, b, c, d, e, f;
		char s[2];
		scanf("%lld %lld %lld %lld %s", &a, &b, &c, &d, s);
		printf("%lld/%lld%s%lld/%lld=", a, b, s, c, d);
		if (s[0] == '+')
		{
			e = a * d + b * c;
			f = b * d;
		}
		else if (s[0] == '-')
		{
			e = a * d - b * c;
			f = b * d;
		}
		else if (s[0] == '*')
		{
			e = a * c;
			f = b * d;
		}
		else
		{
			e = a * d;
			f = b * c;
		}
		if (e == 0)
		{
			printf("0\n");
		}
		else
		{
			if (e < 0)
			{
				e = -e;
				printf("-");
			}
			long long _e = e;
			long long _f = f;
			while (f)
			{
				long long t;
				t = f;
				f = e % f;
				e = t;
			}
			printf("%lld", _e / e);
			if (_f != e)
			{
				printf("/%lld", _f / e);
			}
			printf("\n");
		}
	}
	return 0;
}
