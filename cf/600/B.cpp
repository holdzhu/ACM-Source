#include <cstdio>
#include <algorithm>

using namespace std;

int a[200001];

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", a + i);
	}
	sort(a, a + n);
	for (int i = 0; i < m; ++i)
	{
		int b;
		scanf("%d", &b);
		printf("%d ", lower_bound(a, a + n, b + 1) - a);
	}
	return 0;
}
