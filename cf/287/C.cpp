#include <cstdio>

int main()
{
	long long h, n;
	scanf("%I64d %I64d", &h, &n);
	n = n + ((long long)1<<h) - 1;
	long long s = 0;
	for (int i = 0; i < h; ++i)
	{
		if ((n % 2) ^ (n / 2 % 2))
		{
			s++;
		}
		else
		{
			s += (long long)1<<(i + 1);
		}
		n>>=1;
	}
	printf("%I64d\n", s);
	return 0;
}
