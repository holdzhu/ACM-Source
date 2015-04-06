#include <cstdio>
#include <map>

using namespace std;

long long pro[20];
int n, K;
long long S;
long long a[25];
map<long long, int> ma[26];
long long ans = 0;

int main()
{
	scanf("%d %d %I64d", &n, &K, &S);
	for (int i = 0; i < n; ++i)
	{
		scanf("%I64d", &a[i]);
	}
	pro[0] = 1;
	int maxp;
	for (maxp = 1; pro[maxp - 1] <= S; ++maxp)
	{
		pro[maxp] = pro[maxp - 1] * maxp;
	}
	maxp--;
	int m = n >> 1;
	int num[m];
	for (int i = 0; i < 1 << m; ++i)
	{
		int p = 0;
		for (int j = 0; j < m; ++j)
		{
			if (i & (1 << j))
			{
				num[p++] = j;
			}
		}
		for (int j = 0; j < 1 << p; ++j)
		{
			bool flag = false;
			long long tans = 0;
			int c = 0;
			for (int k = 0; k < p; ++k)
			{
				if (j & (1 << k))
				{
					if (a[num[k]] >= maxp)
					{
						flag = true;
						break;
					}
					tans += pro[a[num[k]]];
					c++;
				}
				else
				{
					tans += a[num[k]];
				}
				if (tans > S || c > K)
				{
					flag = true;
					break;
				}
			}
			if (flag)
			{
				continue;
			}
			ma[c][tans]++;
		}
	}
	for (int i = 0; i < 1 << (n - m); ++i)
	{
		int p = 0;
		for (int j = 0; j < (n - m); ++j)
		{
			if (i & (1 << j))
			{
				num[p++] = j;
			}
		}
		for (int j = 0; j < 1 << p; ++j)
		{
			bool flag = false;
			long long tans = 0;
			int c = 0;
			for (int k = 0; k < p; ++k)
			{
				if (j & (1 << k))
				{
					if (a[m + num[k]] >= maxp)
					{
						flag = true;
						break;
					}
					tans += pro[a[m + num[k]]];
					c++;
				}
				else
				{
					tans += a[m + num[k]];
				}
				if (tans > S || c > K)
				{
					flag = true;
					break;
				}
			}
			if (flag)
			{
				continue;
			}
			for (int i = 0; i <= K - c; ++i)
			{
				if (ma[i].count(S - tans))
				{
					ans += ma[i][S - tans];
				}
			}
		}
	}
	printf("%I64d\n", ans);
	return 0;
}
