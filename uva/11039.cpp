#include <cstdio>
#include <algorithm>

using namespace std;

bool cmp(const int a, const int b)
{
	return abs(a) < abs(b);
}

int main()
{
	int p;
	scanf("%d", &p);
	while (p--)
	{
		int n;
		scanf("%d", &n);
		int a[n];
		for (int i = 0; i < n; ++i)
		{
			scanf("%d", &a[i]);
		}
		sort(a, a + n, cmp);
		int c = 1;
		for (int i = 1; i < n; ++i)
		{
			if (a[i] > 0 ^ a[i - 1] > 0)
			{
				c++;
			}
		}
		printf("%d\n", c);
	}
	return 0;
}
