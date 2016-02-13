#include <cstdio>
#include <algorithm>

using namespace std;

long long cnt[100];

int main()
{
	int n, m;
	while (scanf("%d %d", &n, &m) == 2)
	{
		long long i, j;
		for (int i = 0; i < 100; ++i)
		{
			cnt[i] = 0;
		}
		cnt[1] = 1;
		for (i = 0, j = 2; ; ++i)
		{
			if (i + 2 >= j && j <= m && cnt[i] + cnt[i + 1] + cnt[i + 2] < n)
			{
				j++;
				cnt[i + 2]++;
			}
			for (int k = i - 1; k >= 1 && i + 2 - k <= m; --k)
			{
				cnt[i + 2] += min(cnt[k], n - cnt[i] - cnt[i + 1] - cnt[i + 2]);
			}
			if (cnt[i] + cnt[i] + cnt[i + 1] + cnt[i + 2] > n)
			{
				break;
			}
			cnt[i + 1] += cnt[i];
			cnt[i + 2] += cnt[i];
		}
		long long a = cnt[i], b = cnt[i + 1], c = cnt[i + 2];
		printf("%I64d\n", c * (i + 2) + b * (i + 1) + a * i + (i + 3) * (n - a - b - c));
	}
	return 0;
}
