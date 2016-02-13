#include <cstdio>

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		long long M;
		scanf("%I64d", &M);
		long long ans = 0;
		for (int i = 62; i >= 0; --i)
		{
			ans += (M >> (i + 1ll) << i) + (M >> i & 1ll) * ((M & ((1ll << i) - 1ll)) + 1ll);
		}
		printf("%I64d\n", ans);
	}
	return 0;
}
