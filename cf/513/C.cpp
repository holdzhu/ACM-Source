#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	scanf("%d", &n);
	int l[n], r[n];
	int mr = 0;
	int ml = 10000;
	for (int i = 0; i < n; ++i)
	{
		scanf("%d %d", &l[i], &r[i]);
		if (mr < r[i])
		{
			mr = r[i];
		}
		if (ml > l[i])
		{
			ml = l[i];
		}
	}
	long long c[10001];
	memset(c, 0, sizeof(c));
	for (int i = ml; i <= mr; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (l[j] <= i && i <= r[j])
			{
				int t = 0;
				int id = i * n + j;
				for (int k = 0; k < n; ++k)
				{
					if (j != k && r[k] * n + k > id)
					{
						printf("%d %d %d %d %d\n", i, j, k, r[k] - max(id, l[k] * n + k) / n + 1, max(id, l[k] * n + k) / n);
						t = r[k] - max(id, l[k] * n + k) / n + 1;
						printf("%d\n", t);
						for (int h = 0; h < n; ++h)
						{
							if (h != k && h != j)
							{
								printf("asd %d %d %d\n", h, min(id, r[h] * n + h) / n, l[h]);
								t *= max(min(id, r[h] * n + h) / n - l[h] + 1, 0);
							}
						}
						printf("%d\n", t);
					}
				}
				c[i] += t;
			}
		}
	}
	for (int i = ml; i <= mr; ++i)
	{
		printf("%d %d\n", i, c[i]);
	}
	return 0;
}
