#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int x[100000];

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int n, m, H;
		scanf("%d %d %d", &n, &m, &H);
		for (int i = 0; i < m; ++i)
		{
			scanf("%d", &x[i]);
		}
		sort(x, x + m);
		m = unique(x, x + m) - x;
		int p = 0;
		for (int i = 1; i <= n; ++i)
		{
			if (p < m && x[p] < i)
			{
				p++;
			}
			int h = 0;
			if (p < m) h = max(h, H - (x[p] - i));
			if (p > 0) h = max(h, H - (i - x[p - 1]));
			printf("%d\n", h);
		}
	}
	return 0;
}
