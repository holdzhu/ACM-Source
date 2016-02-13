#include <cstdio>
#include <algorithm>

using namespace std;

int a[2000];

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &a[i]);
	}
	sort(a, a + n);
	int ans = 0;
	for (int i = 0, j = n - 1; i < n; ++i)
	{
		while (j > i && a[i] > 0)
		{
			ans++;
			a[i]--;
			j--;
		}
	}
	printf("%d\n", ans);
	return 0;
}
