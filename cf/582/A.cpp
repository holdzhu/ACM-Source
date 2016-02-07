#include <cstdio>
#include <vector>
#include <map>

using namespace std;

int gcd(int a, int b)
{
	return b ? gcd(b, a % b) : a;
}

int main()
{
	int n;
	scanf("%d", &n);
	map<int, int> mp;
	for (int i = 0; i < n * n; ++i)
	{
		int t;
		scanf("%d", &t);
		mp[t]++;
	}
	vector<int> ans;
	for (int i = 0; i < n; ++i)
	{
		while ((--mp.end())->second == 0)
		{
			mp.erase(--mp.end());
		}
		int mx = (--mp.end())->first;
		ans.push_back(mx);
		for (int j = 0; j < ans.size(); ++j)
		{
			int t = gcd(ans[j], mx);
			for (int ite = 0; ite < (j == ans.size() - 1 ? 1 : 2); ++ite)
			{
				mp[t]--;
			}
		}
		printf("%d ", mx);
	}
	printf("\n");
	return 0;
}
