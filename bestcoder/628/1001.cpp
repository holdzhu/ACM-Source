#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int cnt[100001];

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int n;
		vector<int> extra;
		scanf("%d", &n);
		memset(cnt, 0, sizeof cnt);
		for (int i = 0; i < n; ++i)
		{
			int t;
			scanf("%d", &t);
			int m = sqrt(t + 0.5);
			for (int j = 2; j <= m && t > 1; ++j)
			{
				while (t % j == 0)
				{
					cnt[j]++;
					t /= j;
				}
			}
			if (t > 1)
			{
				extra.push_back(t);
			}
		}
		long long first = -1, second = -1;
		for (int i = 2; i <= 10; ++i)
		{
			if (first == -1 && cnt[i] == 1)
			{
				first = i;
			}
			else if (first == -1 && cnt[i] >= 2)
			{
				first = i;
				second = i;
				break;
			}
			else if (first != -1 && cnt[i] > 0)
			{
				second = i;
				break;
			}
		}
		sort(extra.begin(), extra.end());
		for (int i = 0; i < extra.size() && second == -1; ++i)
		{
			if (first == -1)
			{
				first = extra[i];
			}
			else
			{
				second = extra[i];
				break;
			}
		}
		if (second == -1)
		{
			printf("-1\n");
		}
		else
		{
			printf("%I64d\n", first * second);
		}
	}
	return 0;
}
