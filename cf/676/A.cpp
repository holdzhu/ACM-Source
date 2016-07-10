#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	scanf("%d", &n);
	int p1, p2;
	for (int i = 0; i < n; ++i)
	{
		int a;
		scanf("%d", &a);
		if (a == 1)
			p1 = i;
		else if (a == n)
			p2 = i;
	}
	int ans = max({abs(p1 - p2), abs(n - 1 - p1), abs(n - 1 - p2), abs(p1), abs(p2)});
	printf("%d\n", ans);
	return 0;
}
