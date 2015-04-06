#include <cstdio>

int main()
{
	long long l, r;
	scanf("%lld %lld", &l, &r);
	if (r - l <= 1)
	{
		printf("-1\n");
	}
	else
	{
		if (l % 2)
		{
			if (r - l >= 3)
			{
				printf("%lld %lld %lld\n", l + 1, l + 2, l + 3);
			}
			else
			{
				printf("-1\n");
			}
		}
		else
		{
			printf("%lld %lld %lld\n", l, l + 1, l + 2);
		}
	}
	return 0;
}
