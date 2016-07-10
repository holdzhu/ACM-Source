#include <cstdio>
#include <bitset>
#include <algorithm>
#include <vector>

using namespace std;

bitset<501> dp[501];

int main()
{
	int n, k;
	scanf("%d %d", &n, &k);
	dp[0][0] = 1;
	while (n--)
	{
		int c;
		scanf("%d", &c);
		for (int i = k; i >= c; --i)
			dp[i] |= dp[i - c] | (dp[i - c] << c);
	}
	vector<int> ans;
	for (int i = 0; i <= k; ++i)
		if (dp[k][i])
			ans.push_back(i);
	printf("%d\n", ans.size());
	for (int v: ans)
		printf("%d ", v);
	puts("");
	return 0;
}
