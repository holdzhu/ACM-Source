#include <cstdio>
#define INF 1000000

int mins[200001];

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int n;
		scanf("%d", &n);
		for (int i = 100000 - n; i <= 100000 + n; ++i)
		{
			mins[i] = INF;
		}
		int sum = 0;
		mins[100000] = -1;
		char s[n + 1];
		scanf("%s", s);
		int ans = 0;
		for (int i = 0; i < n; ++i)
		{
			if (s[i] == 'p')
			{
				sum++;
			}
			else if (s[i] == 'c')
			{
				sum--;
			}
			if (mins[sum + 100000] != INF && i - mins[sum + 100000] > ans)
			{
				ans = i - mins[sum + 100000];
			}
			if (mins[sum + 100000] == INF)
			{
				mins[sum + 100000] = i;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
