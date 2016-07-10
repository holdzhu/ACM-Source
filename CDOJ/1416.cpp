#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 1e7;

int p[maxn + 1];
int ans[maxn + 1];
int pre[maxn + 1];
char times[maxn + 1];
bool isnotprime[maxn + 1];
int cnt;

int main()
{
	ans[1] = 1;
	for (int i = 2; i <= maxn; ++i)
	{
		if (!isnotprime[i])
		{
			p[cnt++] = i;
			ans[i] = 1;
			pre[i] = i;
			times[i] = 1;
		}
		for (int j = 0; j < cnt && i * p[j] <= maxn; ++j)
		{
			isnotprime[i * p[j]] = true;
			ans[i * p[j]] = ans[i];
			if (i % p[j])
			{
				if (times[i] == 1)
					ans[i * p[j]] *= pre[i];
				else if (times[i] < 10)
					ans[i * p[j]] *= pre[i] * 10 + times[i];
				else
					ans[i * p[j]] *= pre[i] * 100 + times[i];
				pre[i * p[j]] = p[j];
				times[i * p[j]] = 1;
			}
			else
			{
				pre[i * p[j]] = pre[i];
				times[i * p[j]] = times[i] + 1;
				break;
			}
		}
		if (times[i] == 1)
			ans[i] *= pre[i];
		else if (times[i] < 10)
			ans[i] *= pre[i] * 10 + times[i];
		else
			ans[i] *= pre[i] * 100 + times[i];
	}
	int n;
	scanf("%d", &n);
	long long sum = 0;
	for (int i = 1; i <= n; ++i)
		sum += ans[i];
	printf("%lld\n", sum);
	return 0;
}
