#include <cstdio>
#include <vector>

using namespace std;

const int maxn = 1e7;
vector<int> G[1000];

int main()
{
	freopen("digits.in", "r", stdin);
	freopen("digits.out", "w", stdout);
	for (int i = 1; i <= maxn; ++i)
	{
		int t = i;
		int d = 0;
		while (t)
		{
			d += t % 10;
			t /= 10;
		}
		G[d].push_back(i);
	}
	int n;
	scanf("%d", &n);
	long long ans = 1e18;
	for (int i = 1; i < 1000; ++i)
	{
		if (G[i].size() >= n)
		{
			long long t = 0;
			for (int j = 0; j < n; ++j)
				t += G[i][j];
			if (t < ans)
				ans = t;
		}
	}
	printf("%I64d\n", ans);
	return 0;
}
