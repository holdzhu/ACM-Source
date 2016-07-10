#include <cstdio>

int a[200000];

int main()
{
	int n;
	scanf("%d", &n);
	int mi = 1e9;
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &a[i]);
		if (mi > a[i])
			mi = a[i];
	}
	int mx = 0;
	int cnt = 0;
	for (int i = 0; i < n * 2; ++i)
	{
		if (a[i % n] > mi)
			cnt++;
		else
			cnt = 0;
		if (mx < cnt)
			mx = cnt;
	}
	printf("%I64d\n", 1ll * mi * n + mx);
	return 0;
}
