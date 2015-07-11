#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxF = 86;

long long F[maxF];
int top;
long long dp[2][2];

int main()
{
	F[0] = 1;
	F[1] = 2;
	for (int i = 2; i < maxF; ++i)
	{
		F[i] = F[i - 1] + F[i - 2];
	}
	int T;
	scanf("%d", &T);
	while (T--)
	{
		long long n;
		scanf("%lld", &n);
		int p[maxF];
		int top = 0;
		for (int i = maxF - 1; i >= 0; --i)
		{
			if (F[i] <= n)
			{
				p[top++] = i;
				n -= F[i];
			}
		}
		p[top] = -1;
		memset(dp, 0, sizeof dp);
		dp[0][0] = 1;
		bool pos = 0;
		for (int i = 0; i < top; ++i)
		{
			pos = !pos;
			dp[pos][0] = dp[!pos][0] * ((p[i] - p[i + 1] + 1) / 2) + dp[!pos][1] * ((p[i] - p[i + 1] - 1) / 2);
			dp[pos][1] = (p[i] - p[i + 1] + 1) % 2 * (dp[!pos][0] + dp[!pos][1]);
		}
		printf("%lld\n", dp[pos][0]);
	}
	return 0;
}
