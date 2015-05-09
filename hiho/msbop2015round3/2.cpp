#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

int a[200000];

int main()
{
	int T;
	scanf("%d", &T);
	for (int kase = 0; kase < T; ++kase)
	{
		int n, K;
		scanf("%d %d", &n, &K);
		for (int i = 0; i < n; ++i)
		{
			scanf("%d", &a[i]);
		}
		printf("Case #%d: \n", kase + 1);
		for (int i = 0; i < K; ++i)
		{
			int l, r, k;
			scanf("%d %d %d", &l, &r, &k);
			int ans = 2000000000;
			for (int i = l - 1; i < r; ++i)
			{
				ans = min(ans, abs(a[i] - k));
			}
			printf("%d\n", ans);
		}
	}
	return 0;
}
