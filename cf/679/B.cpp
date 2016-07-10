#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

long long m;
vector<int> ans;

long long tri(int x)
{
	return 1ll * x * x * x;
}

bool check()
{
	long long sum = 0;
	for (int i = 0; i < ans.size(); ++i)
	{
		sum += tri(ans[i]);
		if (sum > min(m, tri(ans[i] + 1) - 1))
			return false;
	}
	return true;
}

int main()
{
	scanf("%I64d", &m);
	int cnt = 0;
	long long sum = 0;
	for (int i = 1; ; ++i)
	{
		if (sum + tri(i) > m)
			break;
		while (sum + tri(i) <= min(tri(i + 1) - 1, m))
		{
			ans.push_back(i);
			cnt++;
			sum += tri(i);
		}
	}
	while (1)
	{
		bool flag = false;
		for (int i = ans.size() - 1; i >= 0; --i)
		{
			if (i == ans.size() - 1 || ans[i] < ans[i + 1])
			{
				ans[i]++;
				if (check())
				{
					flag = true;
					sum = sum - tri(ans[i] - 1) + tri(ans[i]);
					break;
				}
				ans[i]--;
			}
		}
		if (!flag)
			break;
	}
	printf("%d %I64d\n", cnt, sum);
	return 0;
}
