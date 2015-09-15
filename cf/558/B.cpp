#include <cstdio>
#include <cstring>

int left[1000001];
int right[1000001];
int cnt[1000001];

int main()
{
	int n;
	scanf("%d", &n);
	memset(cnt, 0, sizeof cnt);
	for (int i = 0; i < n; ++i)
	{
		int t;
		scanf("%d", &t);
		if (cnt[t] == 0)
		{
			left[t] = i;
		}
		cnt[t]++;
		right[t] = i;
	}
	int maxi = 0;
	for (int i = 1; i <= 1000000; ++i)
	{
		if (cnt[i] > cnt[maxi] || (cnt[i] && cnt[i] == cnt[maxi] && right[i] - left[i] < right[maxi] - left[maxi]))
		{
			maxi = i;
		}
	}
	printf("%d %d\n", left[maxi] + 1, right[maxi] + 1);
	return 0;
}
