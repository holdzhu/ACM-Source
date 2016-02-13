#include <cstdio>
#include <map>
#include <algorithm>

using namespace std;

int main()
{
	freopen("millenium.in", "r", stdin);
	freopen("millenium.out", "w", stdout);
	int N, A, B;
	scanf("%d %d %d", &N, &A, &B);
	map<int, int> ma;
	for (int i = 0; i < N; ++i)
	{
		int x;
		scanf("%d %*I64d", &x);
		ma[x]++;
	}
	int ans = 0;
	while (ma.size())
	{
		int x = ma.begin()->first;
		int cnt = ma.begin()->second;
		ma.erase(ma.begin());
		ans = max(ans, x);
		if (cnt > B)
			ma[x + 1] += cnt - B;
	}
	printf("%d\n", ans);
	return 0;
}
