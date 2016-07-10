#include <cstdio>
#include <vector>

using namespace std;

const int maxn = 2e6;
bool isnotprime[maxn + 1];
int p[maxn + 1];
int cnt = 0;
int a[1000];

int main()
{
	for (int i = 2; i <= maxn; ++i)
	{
		if (!isnotprime[i])
			p[cnt++] = i;
		for (int j = 0; j < cnt && i * p[j] <= maxn; ++j)
		{
			isnotprime[i * p[j]] = true;
			if (i % p[j] == 0)
				break;
		}
	}
	int n;
	scanf("%d", &n);
	int one = 0;
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &a[i]);
		one += a[i] == 1;
	}
	vector<int> ans;
	for (int i = 0; i < n; ++i)
	{
		if (a[i] == 0)
			continue;
		if (!isnotprime[a[i] + 1])
		{
			ans.push_back(a[i]);
			for (int j = 0; j < one; ++j)
				ans.push_back(1);
			break;
		}
	}
	if (!ans.size())
		for (int i = 0; i < one; ++i)
			ans.push_back(1);
	if (ans.size() < 2)
		for (int i = 0; i < n; ++i)
		{
			for (int j = i + 1; j < n; ++j)
			{
				if (!isnotprime[a[i] + a[j]])
				{
					ans = {a[i], a[j]};
				}
			}
		}
	if (ans.size() < 1)
		ans = {a[0]};
	printf("%d\n", ans.size());
	for (int i = 0; i < ans.size(); ++i)
		printf("%d ", ans[i]);
	puts("");
	return 0;
}