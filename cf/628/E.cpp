#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

const int maxn = 3010;

int tree[maxn];

inline int lowbit(int x)
{
	return x & (-x);
}

void update(int x, int val)
{
	x++;
	while (x < maxn)
	{
		tree[x] += val;
		x += lowbit(x);
	}
}

int query(int x)
{
	x++;
	int ret = 0;
	while (x > 0)
	{
		ret += tree[x];
		x -= lowbit(x);
	}
	return ret;
}

int n, m;
char s[maxn][maxn];
int leftmost[maxn][maxn];
int rightmost[maxn][maxn];
vector<int> over[maxn];

long long check(int x, int y)
{
	memset(tree, 0, sizeof tree);
	int l = min(x + 1, m - y);
	for (int i = 0; i < l; ++i)
		over[i].clear();
	int last = -1;
	long long ret = 0;
	for (int i = 0; i < l; ++i)
	{
		int nx = x - i;
		int ny = y + i;
		if (s[nx][ny] == '.')
			last = i;
		else
		{
			update(i, 1);
			over[i + rightmost[nx][ny] - ny].push_back(i);
			int len = min(ny - leftmost[nx][ny] + 1, i - last);
			ret += query(i) - query(i - len);
		}
		for (int j: over[i])
			update(j, -1);
	}
	return ret;
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; ++i)
		scanf("%s", s[i]);
	for (int i = 0; i < n; ++i)
	{
		leftmost[i][0] = 0;
		for (int j = 1; j < m; ++j)
			leftmost[i][j] = s[i][j - 1] == 'z' ? leftmost[i][j - 1] : j;
		rightmost[i][m - 1] = m - 1;
		for (int j = m - 2; j >= 0; --j)
			rightmost[i][j] = s[i][j + 1] == 'z' ? rightmost[i][j + 1] : j;
	}
	long long ans = 0;
	for (int i = 0; i < n; ++i)
		ans += check(i, 0);
	for (int i = 1; i < m; ++i)
		ans += check(n - 1, i);
	printf("%I64d\n", ans);
	return 0;
}
