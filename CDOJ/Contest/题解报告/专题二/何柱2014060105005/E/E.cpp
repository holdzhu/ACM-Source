#include <cstdio>
#include <cstring>
#include <algorithm>
#include <functional>

using namespace std;

int a[64];
int N;
bool vis[64];
int target;
int sum;

bool dfs(int de, int x, int w)
{
	if (w == target)
	{
		if (de + 2 >= sum / target)
		{
			return true;
		}
		int first = 1;
		while (vis[first])
		{
			first++;
		}
		vis[first] = true;
		if (dfs(de + 1, first + 1, a[first]))
		{
			return true;
		}
		vis[first] = false;
	}
	else if (w > target - a[N - 1])
	{
		return false;
	}
	else
	{
		if (x < N) for (int i = x; i < N; ++i)
		{
			if (!vis[i] && w + a[i] <= target && (a[i] != a[i - 1] || vis[i - 1]))
			{
				vis[i] = true;
				if (dfs(de, i + 1, w + a[i]))
				{
					return true;
				}
				vis[i] = false;
				if (w + a[i] == target)
				{
					break;
				}
			}
		}
	}
	return false;
}

int main()
{
	while (scanf("%d", &N) == 1 && N)
	{
		sum = 0;
		for (int i = 0; i < N; ++i)
		{
			scanf("%d", &a[i]);
			sum += a[i];
		}
		sort(a, a + N, greater<int>());
		memset(vis, 0, sizeof vis);
		vis[0] = true;
		bool flag = false;
		for (int i = a[0]; i <= sum / 2; ++i)
		{
			if (sum % i == 0)
			{
				target = i;
				if (dfs(0, 1, a[0]))
				{
					printf("%d\n", target);
					flag = true;
					break;
				}
			}
		}
		if (!flag)
		{
			printf("%d\n", sum);
		}
	}
	return 0;
}
