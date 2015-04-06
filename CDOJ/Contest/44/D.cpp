#include <cstdio>
#include <cmath>

using namespace std;

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int n;
		scanf("%d", &n);
		int a[n];
		int s = 0;
		for (int i = 0; i < n; ++i)
		{
			scanf("%d", &a[i]);
			s += a[i];
		}
		if (n == 1)
		{
			printf("0\n");
		}
		else
		{
			if (n % 2 == 0 && s % 2 == 1)
			{
				printf("-1\n");
			}
			else
			{
				int l = n / 2;
				for (int i = 0; i < l; ++i)
				{
					a[i] -= a[n - 1 - i];
				}
				int c = 0;
				for (int i = 0; i < l - 1; ++i)
				{
					c += abs(a[i]);
					a[i + 1]  += a[i];
				}
				if (n % 2)
				{
					c += abs(a[l - 1]);
				}
				else
				{
					c += abs(a[l - 1]) / 2;
				}
				printf("%d\n", c);
			}
		}
	}
	return 0;
}
