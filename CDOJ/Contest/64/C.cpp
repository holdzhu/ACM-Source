#include <cstdio>

char s[100];

long long gcd(long long a, long long b)
{
	return b == 0 ? a : gcd(b, a % b);
}

int main()
{
	int n;
	int Test = 1;
	while (scanf("%d", &n) == 1 && n)
	{
		long long up = 0;
		long long down = 1;
		for (int i = 0; i < n; ++i)
		{
			while (gets(s) && s[0] == 0);
			int num[3] = {0, 0, 0};
			int type = 0;
			for (int i = 0; s[i]; ++i)
			{
				if (s[i] >= '0' && s[i] <= '9')
				{
					num[type] *= 10;
					num[type] += s[i] - '0';
				}
				else
				{
					type++;
				}
			}
			if (type == 0)
			{
				up += num[0] * down;
			}
			else if (type == 1 && num[1] != 0)
			{
				int fac = gcd(num[0], num[1]);
				num[0] /= fac;
				num[1] /= fac;
				fac = gcd(down, num[1]);
				int newdown = down / fac * num[1];
				int newup = up * (num[1] / fac) + num[0] * (down / fac);
				down = newdown;
				up = newup;
			}
			else if (type == 2 && num[2] != 0)
			{
				int fac = gcd(num[1], num[2]);
				num[1] /= fac;
				num[2] /= fac;
				num[1] += num[0] * num[2];
				fac = gcd(down, num[2]);
				int newdown = down / fac * num[2];
				int newup = up * (num[2] / fac) + num[1] * (down / fac);
				down = newdown;
				up = newup;
			}
			int fac = gcd(up, down);
			up /= fac;
			down /= fac;
		}
		printf("Test %d: ", Test++);
		if (down == 1)
		{
			printf("%lld\n", up);
		}
		else if (up > down)
		{
			printf("%lld,%lld/%lld\n", up / down, up % down, down);
		}
		else
		{
			printf("%lld/%lld\n", up, down);
		}
	}
	return 0;
}
