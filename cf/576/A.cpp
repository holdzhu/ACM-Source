#include <cstdio>
#include <vector>

using namespace std;

vector<int> ans;

bool vis[2000];

int main()
{
	int n;
	scanf("%d", &n);
	for (int j = 1; j <= n; ++j)
	{
		int tt = j;
		for (int i = 2; i <= j; ++i)
		{
			int t = 1;
			while (tt % i == 0)
			{
				tt /= i;
				t *= i;
				vis[t] = true;
			}
		}
	}
	for (int i = 0; i < 2000; ++i)
	{
		if (vis[i])
		{
			ans.push_back(i);
		}
	}
	printf("%d\n", ans.size());
	for (int i = 0; i < ans.size(); ++i)
	{
		printf("%d ", ans[i]);
	}
	printf("\n");
	return 0;
}
