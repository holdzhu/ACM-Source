#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int n;
		scanf("%d", &n);
		int a[n][n];
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < i + 1; ++j)
			{
				int t;
				scanf("%d", &t);
				a[i][j] = t;
			}
		}
		for (int i = n - 2; i >= 0; --i)
		{
			for (int j = 0; j < i + 1; ++j)
			{
				a[i][j] += max(a[i + 1][j], a[i + 1][j + 1]);
			}
		}
		printf("%d\n", a[0][0]);
	}
	return 0;
}
