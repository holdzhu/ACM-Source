#include <cstdio>
#include <cstring>

int a[10001];

int main()
{
	int n;
	while (scanf("%d", &n) == 1)
	{
		memset(a, 0, sizeof a);
		for (int i = 0; i < n; ++i)
		{
			int t;
			scanf("%d", &t);
			a[t]++;
		}
		int flag = -1;
		for (int i = 1; i <= 10000; ++i)
		{
			if (n - a[i] < a[i])
			{
				flag = i;
				break;
			}
		}
		printf("%d\n", flag);
	}
	return 0;
}
