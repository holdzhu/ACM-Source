#include <cstdio>

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int n;
		scanf("%d", &n);
		long long maxm = 0;
		long long s = 0;
		while (n--)
		{
			long long t;
			scanf("%lld", &t);
			if (t > maxm)
			{
				maxm = t;
			}
			s += t;
		}
		if (maxm > (s + 1) / 2)
		{
			printf("No\n");
		}
		else
		{
			printf("Yes\n");
		}
	}
	return 0;
}
