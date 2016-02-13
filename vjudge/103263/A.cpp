#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
	int n, m, a, b;
	scanf("%d %d %d %d", &n, &m, &a, &b);
	int ans = 1e9;
	for (int i = 0; i <= n; ++i)
	{
		ans = min(ans, i * a + (n - i + m - 1) / m * b);
	}
	printf("%d\n", ans);
	return 0;
}
