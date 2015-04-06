#include <cstdio>
#include <cstring>

const int mod = 1000000007;

long long l, r;
int k;
int num[20];
int d[20][2][200];
bool vis[20][2];

int dfs(int x, int b, int kk, bool flag)
{
	if (x < 0)
	{
		return 0;
	}

}

int main()
{
	long long l, r;
	scanf("%lld %lld %d", &l, &r, &k);
	memset(num, 0, sizeof(num));
	int p = 0;
	while (l)
	{
		num[p++] = l % 10;
		l /= 10;
	}
	dfs(19, 0, true);
	return 0;
}
