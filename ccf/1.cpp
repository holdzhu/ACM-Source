#include <cstdio>
#include <cstring>

int cnt[10001];

int main()
{
	int n;
	scanf("%d", &n);
	memset(cnt, 0, sizeof cnt);
	while (n--)
	{
		int t;
		scanf("%d", &t);
		cnt[t]++;
	}
	int maxi = 0;
	for (int i = 1; i <= 10000; ++i)
	{
		if (cnt[i] > cnt[maxi])
		{
			maxi = i;
		}
	}
	printf("%d\n", maxi);
	return 0;
}
