#include <cstdio>
#include <climits>
#include <algorithm>

using namespace std;

int a[100000];

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < n; ++i)
	{
		int mi = INT_MAX;
		if (i > 0)
		{
			mi = min(mi, a[i] - a[i - 1]);
		}
		if (i < n - 1)
		{
			mi = min(mi, a[i + 1] - a[i]);
		}
		printf("%d %d\n", mi, max(a[i] - a[0], a[n - 1] - a[i]));
	}
	return 0;
}
