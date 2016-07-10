#include <cstdio>
#include <algorithm>

using namespace std;

int cnt[100];

int main()
{
	int n, k;
	scanf("%d %d", &n, &k);
	while (n--)
	{
		int a;
		scanf("%d", &a);
		++cnt[a % k];
	}
	int ans = 0;
	for (int i = 1; i <= (k - 1) / 2; ++i)
		ans += max(cnt[i], cnt[k - i]);
	ans += min(cnt[0], 1);
	if (~k & 1)
		ans += min(cnt[k / 2], 1);
	printf("%d\n", ans);
	return 0;
}
