#include <cstdio>

int h[1000];

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &h[i]);
	}
	int ans = 0;
	for (int i = 0; i < n; ++i)
	{
		int l = i - 1;
		int r = i + 1;
		for (; l >= 0 && h[l] >= h[i]; --l);
		for (; r < n && h[r] >= h[i]; ++r);
		if (ans < h[i] * (r - l - 1))
		{
			ans = h[i] * (r - l - 1);
		}
	}
	printf("%d\n", ans);
	return 0;
}
