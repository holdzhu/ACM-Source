#include <cstdio>

int cnt1[2001];
int cnt2[2001];

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		int x, y;
		scanf("%d %d", &x, &y);
		cnt1[x + y]++;
		cnt2[x - y + 1000]++;
	}
	long long sum = 0;
	for (int i = 0; i <= 2000; ++i)
	{
		sum += 1ll * cnt1[i] * (cnt1[i] - 1) / 2;
		sum += 1ll * cnt2[i] * (cnt2[i] - 1) / 2;
	}
	printf("%I64d\n", sum);
	return 0;
}