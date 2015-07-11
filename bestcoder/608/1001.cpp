#include <cstdio>

int a[1000];
long long s[1001];

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int n, P;
		scanf("%d %d", &n, &P);
		for (int i = 0; i < n; ++i)
		{
			scanf("%d", &a[i]);
		}
		long long ans = -1000000000000LL;
		for (int i = 0; i < n; ++i)
		{
			int tmp = a[i];
			a[i] = P;
			int mini = 0;
			int maxi = 0;
			long long sum = -10000000000000LL;
			s[0] = 0;
			for (int i = 0; i < n; ++i)
			{
				s[i + 1] = s[i] + a[i];
			}
			for (int j = 1; j <= n; ++j)
			{
				if (s[j] > s[maxi])
				{
					maxi = j;
				}
				if (s[j] < s[mini])
				{
					mini = j;
					maxi = j;
				}
				if (s[maxi] - s[mini] > sum && maxi != mini)
				{
					sum = s[maxi] - s[mini];
				}
			}
			if (sum == -10000000000000LL)
			{
				for (int i = 0; i < n; ++i)
				{
					if (a[i] > sum)
					{
						sum = a[i];
					}
				}
			}
			if (sum > ans)
			{
				ans = sum;
			}
			a[i] = tmp;
		}
		printf("%I64d\n", ans);
	}
	return 0;
}
