#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int a[1000000];
long long sum[3000001];
int d[1000000][50];
long long qq[50];
int p[50];

bool cmp(const int a, const int b)
{
	return qq[a] < qq[b];
}

int main()
{
	int n, q;
	scanf("%d %d", &n, &q);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &a[i]);
	}
	sum[0] = 0;
	for (int i = 0; i < n * 3; ++i)
	{
		sum[i + 1] = sum[i] + a[i % n];
	}
	for (int i = 0; i < q; ++i)
	{
		scanf("%I64d", &qq[i]);
		q[i] = i;
	}
	sort(p, p + q, cmp);
	for (int i = 0; i < n; ++i)
	{
		d[i][j] = upper_bound(sum + i, sum + i + n + 1, sum[l] + b) - sum - 1;		
		for (int j = 0; j < p; ++j)
		{
			d[i][j] = upper_bound(sum + d[i][j - 1], sum + d[i][j - 1] + n + 1, sum[d[i][j - 1]] + b) - sum - 1;		
		}
	}
	int ans[q];
	for (int k = 0; k < q; ++k)
	{
		for (int i = 0; i < n; ++i)
		{
			if (!vis[i])
			{
				int c = 0;
				int l = i;
				while (l < i + n)
				{
					vis[l % n] = true;
					l = d[l % n][k];
					c++;
					if (c >= ans)
					{
						break;
					}
				}
				if (c < ans[p[k]])
				{
					ans[p[k]] = c;
				}
			}
		}
	}
	for (int i = 0; i < p; ++i)
	{
		printf("%d\n", ans[i]);
	}
	return 0;
}
