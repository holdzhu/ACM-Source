#include <cstdio>
#include <algorithm>

using namespace std;

int n, a, b, T;
char s[500001];

int solve()
{
	int ret = 0;
	long long sum1 = 0, sum2 = 0;
	sum1 = 1 + (int)(s[0] == 'w') * b;
	for (int i = 0, j = n; i < n - 1; ++i)
	{
		while (j > 0 && sum1 + sum2 + 1 + a + (int)(s[j - 1] == 'w') * b <= T)
		{
			j--;
			sum2 += 1 + a + (int)(s[j] == 'w') * b;
		}
		while (j < n && sum1 + sum2 > T)
		{
			sum2 -= 1 + a + (int)(s[j] == 'w') * b;
			j++;
		}
		if (sum1 + sum2 > T)
			break;
		ret = max(ret, i + 1 + (n - j));
		sum1 += 1 + a + a + (int)(s[i + 1] == 'w') * b;
	}
	return ret;
}

int main()
{
	scanf("%d %d %d %d", &n, &a, &b, &T);
	scanf("%s", s);
	long long sum = 0;
	for (int i = 0; i < n; ++i)
	{
		if (s[i] == 'w')
			sum += b + 1;
		else
			sum += 1;
	}
	if (sum + 1ll * a * (n - 1) <= T)
		printf("%d\n", n);
	else
	{
		int ans = solve();
		for (int i = 1; i <= n / 2; ++i)
			swap(s[i], s[n - i]);
		ans = max(ans, solve());
		printf("%d\n", ans);
	}
	return 0;
}
