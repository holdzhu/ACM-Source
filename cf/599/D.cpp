#include <cstdio>

long long a[2000000];
long long b[2000000];
int cnt = 0;

int main()
{
	long long n;
	scanf("%I64d", &n);
	long long s = 0;
	for (int i = 1; ; ++i)
	{
		s += 1ll * i * i;
		if (s > n)
		{
			break;
		}
		if ((n - s) * 2 % (1ll * i * (i + 1)) == 0)
		{
			long long j = (n - s) * 2 / i / (i + 1) + i;
			if (j >= i)
			{
				a[cnt] = i;
				b[cnt] = j;
				cnt++;
			}
		}
	}
	printf("%d\n", cnt * 2 - (a[cnt - 1] == b[cnt - 1]));
	for (int i = 0; i < cnt; ++i)
	{
		printf("%I64d %I64d\n", a[i], b[i]);
	}
	for (int i = cnt - 1 - (a[cnt - 1] == b[cnt - 1]); i >= 0; --i)
	{
		printf("%I64d %I64d\n", b[i], a[i]);
	}
	return 0;
}
