#include <cstdio>
#include <set>
#include <algorithm>

using namespace std;

int main()
{
	freopen("bricks.in", "r", stdin);
	freopen("bricks.out", "w", stdout);
	int n, k;
	scanf("%d %d", &n, &k);
	set<pair<int, int> > s;
	for (int i = 0; i < k; ++i)
	{
		int x, y;
		scanf("%d %d", &x, &y);
		if ((x >= 2 && y >= 2 && !s.count(make_pair(x - 1, y - 1)) && s.count(make_pair(x, y - 1))) ||
			(x >= 2 && y <= x - 1 && !s.count(make_pair(x - 1, y)) && s.count(make_pair(x, y + 1))))
		{
			printf("%d\n", i + 1);
			return 0;
		}
		s.insert(make_pair(x, y));
	}
	printf("-1\n");
	return 0;
}
