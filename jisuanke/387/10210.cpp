#include <cstdio>
#include <algorithm>
#include <map>

using namespace std;

int cnt[26];
int sum;

int p[51][50];

int findset(int *p, int x)
{
	return x == p[x] ? x : p[x] = findset(p, p[x]);
}

int ans;

void dfs(int d)
{
	if (d < 0)
	{
		map<int, int> mp;
		for (int i = 0; i < sum; ++i)
			mp[findset(p[0], i)]++;
		
	}
	for (int i = 0; i < sum; ++i)
		p[d][i] = p[d + 1][i];
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		sum = 0;
		for (int i = 0; i < 26; ++i)
		{
			scanf("%d", &cnt[i]);
			sum += cnt[i];
		}
		sort(cnt, cnt + 26);
		for (int i = 0; i < sum; ++i)
			p[sum][i] = i;
		ans = 0;
		dfs(sum - 1);
		printf("%d\n", ans);
	}
	return 0;
}
