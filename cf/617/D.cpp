#include <cstdio>
#include <algorithm>

using namespace std;

int x[3], y[3];

bool in(int x, int l, int r)
{
	return (x > l && x < r) || (x > r && x < l);
}

int main()
{
	for (int i = 0; i < 3; ++i)
	{
		scanf("%d %d", &x[i], &y[i]);
	}
	int ans = 3;
	if (x[0] == x[1] && x[0] == x[2])
		ans = min(ans, 1);
	if (y[0] == y[1] && y[0] == y[2])
		ans = min(ans, 1);
	if ((x[0] == x[1] && !in(y[2], y[0], y[1])) || (x[0] == x[2] && !in(y[1], y[0], y[2])) || (x[2] == x[1] && !in(y[0], y[2], y[1])))
		ans = min(ans, 2);
	if ((y[0] == y[1] && !in(x[2], x[0], x[1])) || (y[0] == y[2] && !in(x[1], x[0], x[2])) || (y[2] == y[1] && !in(x[0], x[2], x[1])))
		ans = min(ans, 2);
	printf("%d\n", ans);
	return 0;
}
