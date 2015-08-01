#include <cstdio>
#include <algorithm>

using namespace std;

int s[50000];
int cnt;

int main()
{
	int T;
	for (cnt = 0; ; ++cnt)
	{
		s[cnt] = 3 * cnt * (cnt + 1) + 1;
		if (s[cnt] > 1e9)
		{
			break;
		}
	}
	scanf("%d", &T);
	while (T--)
	{
		int m;
		scanf("%d", &m);
		int maxn = upper_bound(s, s + cnt, m) - s - 1;
		long long ans = 0;
		for (int i = maxn; i >= 0; --i)
		{
			ans += m / s[i];
			m -= m / s[i] * s[i];
			i = upper_bound(s, s + cnt, m) - s;
		}
		printf("%I64d\n", ans);
	}
	return 0;
}
