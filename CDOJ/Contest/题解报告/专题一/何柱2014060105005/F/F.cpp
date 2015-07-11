#include <cstdio>
#include <algorithm>

using namespace std;

int a[125002];

int main()
{
	int n;
	scanf("%d", &n);
	int m = n / 2 + 1;
	for (int i = 1; i <= m; ++i)
	{
		scanf("%d", &a[i]);
	}
	sort(a + 1, a + m + 1, greater<int>());
	for (int i = 0; i < n - m; ++i)
	{
		int t;
		scanf("%d", &t);
		if (t < a[1])
		{
			a[1] = t;
			int u = 1;
			while (1)
			{
				if ((u << 1 | 1) <= m && (a[u << 1] > a[u] || a[u << 1 | 1] > a[u]))
				{
					if (a[u << 1] >= a[u << 1 | 1])
					{
						swap(a[u << 1], a[u]);
						u = u << 1;
					}
					else
					{
						swap(a[u << 1 | 1], a[u]);
						u = u << 1 | 1;
					}
				}
				else if ((u << 1) <= m && a[u << 1] > a[u])
				{
					swap(a[u << 1], a[u]);
					u = u << 1;
				}
				else
				{
					break;
				}
			}
		}
	}
	if (n % 2)
	{
		printf("%d.0\n", a[1]);
	}
	else
	{
		if (n == 2)
		{
			printf("%.1f\n", a[1] * 0.5 + a[2] * 0.5);
		}
		else
		{
			printf("%.1f\n", a[1] * 0.5 + max(a[2], a[3]) * 0.5);
		}
	}
	return 0;
}
