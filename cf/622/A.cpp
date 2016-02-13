#include <cstdio>

int main()
{
	long long n;
	scanf("%I64d", &n);
	for (int i = 1; ; ++i)
	{
		if (n <= i)
		{
			printf("%I64d\n", n);
			break;
		}
		n -= i;
	}
	return 0;
}
