#include <cstdio>
#include <map>

using namespace std;

int a[2000], b[2000];

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d", &a[i]);
	int m;
	scanf("%d", &m);
	for (int i = 0; i < m; ++i)
		scanf("%d", &b[i]);
	long long sum1 = 0, sum2 = 0;
	for (int i = 0; i < n; ++i)
		sum1 += a[i];
	for (int i = 0; i < m; ++i)
		sum2 += b[i];
	map<long long, int> sgl;
	for (int i = 0; i < n; ++i)
		sgl[a[i]] = i;
	map<long long, pair<int, int> > dbl;
	for (int i = 0; i < n; ++i)
		for (int j = i + 1; j < n; ++j)
			dbl[a[i] + a[j]] = make_pair(i, j);
	long long ans1 = 1e18;
	for (int i = 0; i < m; ++i)
	{
		auto it = sgl.lower_bound((sum1 + 2ll * b[i] - sum2) / 2);
		if (it != sgl.end())
			ans1 = min(ans1, abs(sum1 + 2ll * b[i] - sum2 - 2ll * it->first));
		if (it != sgl.begin())
			ans1 = min(ans1, abs(sum1 + 2ll * b[i] - sum2 - 2ll * (--it)->first));
	}
	long long ans2 = 1e18;
	for (int i = 0; i < m; ++i)
		for (int j = i + 1; j < m; ++j)
		{
			auto it = dbl.lower_bound((sum1 + 2ll * (b[i] + b[j]) - sum2) / 2);
			if (it != dbl.end())
				ans2 = min(ans2, abs(sum1 + 2ll * (b[i] + b[j]) - sum2 - 2ll * it->first));
			if (it != dbl.begin())
				ans2 = min(ans2, abs(sum1 + 2ll * (b[i] + b[j]) - sum2 - 2ll * (--it)->first));
		}
	long long ans = abs(sum1 - sum2);
	if (ans <= ans1 && ans <= ans2)
		printf("%I64d\n", ans), puts("0");
	else if (ans1 <= ans2)
	{
		printf("%I64d\n", ans1);
		puts("1");
		for (int i = 0; i < m; ++i)
		{
			auto it = sgl.lower_bound((sum1 + 2ll * b[i] - sum2) / 2);
			if (it != sgl.end())
			{
				long long tmp = abs(sum1 + 2ll * b[i] - sum2 - 2ll * it->first);
				if (tmp == ans1)
				{
					printf("%d %d\n", it->second + 1, i + 1);
					break;
				}
			}
			if (it != sgl.begin())
			{
				long long tmp = abs(sum1 + 2ll * b[i] - sum2 - 2ll * (--it)->first);
				if (tmp == ans1)
				{
					printf("%d %d\n", it->second + 1, i + 1);
					break;
				}
			}
		}
	}
	else
	{
		printf("%I64d\n", ans2);
		puts("2");
		for (int i = 0; i < m; ++i)
			for (int j = i + 1; j < m; ++j)
			{
				auto it = dbl.lower_bound((sum1 + 2ll * (b[i] + b[j]) - sum2) / 2);
				if (it != dbl.end())
				{
					long long tmp = abs(sum1 + 2ll * (b[i] + b[j]) - sum2 - 2ll * it->first);
					if (tmp == ans2)
					{
						printf("%d %d\n%d %d\n", it->second.first + 1, i + 1, it->second.second + 1, j + 1);
						return 0;
					}
				}
				if (it != dbl.begin())
				{
					long long tmp = abs(sum1 + 2ll * (b[i] + b[j]) - sum2 - 2ll * (--it)->first);
					if (tmp == ans2)
					{
						printf("%d %d\n%d %d\n", it->second.first + 1, i + 1, it->second.second + 1, j + 1);
						return 0;
					}
				}
			}
	}
	return 0;
}
