#include <cstdio>

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		long long A, B, D;
		scanf("%lld %lld %lld", &A, &B, &D);
		if (A + B == D)
		{
			printf("+\n");
		}
		else if (A - B == D)
		{
			printf("-\n");
		}
		else if (A * B == D)
		{
			printf("*\n");
		}
		else
		{
			printf("/\n");
		}
	}
	return 0;
}
