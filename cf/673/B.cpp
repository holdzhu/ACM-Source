#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	int l = 1;
	int r = n - 1;
	for (int i = 0; i < m; ++i)
	{
		int u, v;
		scanf("%d %d", &u, &v);
		if (u > v)
			swap(u, v);
		l = max(l, u);
		r = min(r, v - 1);
	}
	printf("%d\n", max(r - l + 1, 0));
	return 0;
}
