#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxF = 24;

int F[maxF];
int ans[100001][maxF];
int top;

int main()
{
	F[0] = 1;
	F[1] = 2;
	for (int i = 2; i < maxF; ++i)
	{
		F[i] = F[i - 1] + F[i - 2];
	}
	memset(ans, 0, sizeof ans);
	ans[1][0] = 1;
	for (int i = 1; i <= 100000; ++i)
	{
		for (int j = 1; j < maxF && F[j] <= i; ++j)
		{
			if (F[j] == i)
			{
				ans[i][j] = 1;
			}
			else
			{
				ans[i][j] += ans[i - F[j]][j - 1];
			}
		}
		for (int j = 1; j < maxF; ++j)
		{
			ans[i][j] += ans[i][j - 1];
		}
	}
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int n;
		scanf("%d", &n);
		printf("%d\n", ans[n][maxF - 1]);
	}
	return 0;
}
