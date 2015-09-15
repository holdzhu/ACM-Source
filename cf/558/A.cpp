#include <cstdio>
#include <algorithm>

using namespace std;

struct Tree
{
	int x, a;
	bool operator < (const Tree& rhs) const
	{
		return x < rhs.x;
	}
};

Tree tree[100];

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d %d", &tree[i].x, &tree[i].a);
	}
	sort(tree, tree + n);
	int lz = 0;
	int gz = 0;
	for (int i = 0; i < n; ++i)
	{
		if (tree[i].x < 0)
		{
			lz++;
		}
		else if (tree[i].a > 0)
		{
			gz++;
		}
	}
	int left = 0;
	int right = n;
	if (lz > gz + 1)
	{
		left = lz - gz - 1;
	}
	else if (lz + 1 < gz)
	{
		right = n - gz + lz + 1;
	}
	int ans = 0;
	for (int i = left; i < right; ++i)
	{
		ans += tree[i].a;
	}
	printf("%d\n", ans);
	return 0;
}
