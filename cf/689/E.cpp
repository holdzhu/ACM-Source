#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 2e5;
const int mod = 1e9 + 7;

long long fac[maxn + 1];
long long inv[maxn + 1];
long long facinv[maxn + 1];
pair<int, int> events[maxn * 2];

int main()
{
	int n, k;
	scanf("%d %d", &n, &k);
	fac[0] = fac[1] = inv[1] = facinv[0] = facinv[1] = 1;
	for (int i = 2; i <= n; ++i)
	{
		fac[i] = fac[i - 1] * i % mod;
		inv[i] = inv[mod % i] * (mod - mod / i) % mod;
		facinv[i] = facinv[i - 1] * inv[i] % mod;
	}
	for (int i = 0; i < n; ++i)
	{
		int l, r;
		scanf("%d %d", &l, &r);
		events[i * 2] = {l, 1};
		events[i * 2 + 1] = {r + 1, -1};
	}
	sort(events, events + n * 2);
	int sum = 0;
	long long ans = 0;
	for (int i = 0; i < n * 2; ++i)
	{
		if (sum >= k)
		{
			int delta = events[i].first - events[i - 1].first;
			long long cnt = fac[sum] * facinv[k] % mod * facinv[sum - k] % mod;
			ans += delta * cnt % mod;
			if (ans >= mod)
				ans -= mod;
		}
		sum += events[i].second;
	}
	printf("%I64d\n", ans);
	return 0;
}
