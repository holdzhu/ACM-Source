#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	while (scanf("%d", &n) == 1 && n)
	{
		int a[n];
		int b[n];
		for (int i = 0; i < n; ++i)
		{
			scanf("%d", &a[i]);
		}
		for (int i = 0; i < n; ++i)
		{
			scanf("%d", &b[i]);
		}
		sort(a, a + n);
		sort(b, b + n);
		int p = 0;
		int e = 0;
		int s = 0;
		for (int i = 0; i < n - e; ++i)
		{
			if (a[i] > b[p])
			{
				s++;
				p++;
			}
			else if (a[i] < b[p])
			{
				if (a[i] < b[n - 1 - i + p - e])
				{
					s--;
				}
			}
			else
			{
				while (a[n - 1 - e] > b[n - 1 - i + p - e])
				{
					e++;
					s++;
				}
				if (a[i] < b[n - 1 - i + p - e])
				{
					s--;
				}
			}
		}
		printf("%d\n", s * 200);
	}
	return 0;
}
