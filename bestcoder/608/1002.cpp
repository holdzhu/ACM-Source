#include <cstdio>
#include <functional>
#include <algorithm>

using namespace std;

int a[100000];
int b[100000];

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int n, m;
		scanf("%d %d", &n, &m);
		for (int i = 0; i < n; ++i)
		{
			scanf("%d", &a[i]);
		}
		for (int i = 0; i < m; ++i)
		{
			scanf("%d", &b[i]);
		}
		sort(a, a + n, greater<int>());
		sort(b, b + m);
		long long sum = 0;
		for (int i = 0; i < n && i < m && a[i] > b[i]; ++i)
		{
			sum += a[i] - b[i];
		}
		printf("%I64d\n", sum);
	}
	return 0;
}
