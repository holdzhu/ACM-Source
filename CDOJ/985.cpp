#include <cstdio>

int main()
{
	int T;
	printf("1 5 6 25 76 376 625 9376 \n");
	scanf("%d", &T);
	while (T--)
	{
		long long n;
		scanf("%lld", &n);
		long long s = n * n;
		bool y = false;
		int t = 10;
		for (int i = 0; i < 10; ++i)
		{
			if (s % t == n)
			{
				y = true;
				break;
			}
			t *= 10;
		}
		if (y)
		{
			printf("Yes\n");
		}
		else
		{
			printf("No\n");
		}
	}
	return 0;
}
