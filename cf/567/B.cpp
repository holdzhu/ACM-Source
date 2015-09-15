#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

bool vis[1000001];

int main()
{
	int n;
	scanf("%d", &n);
	memset(vis, 0, sizeof vis);
	int ans = 0;
	int cur = 0;
	while (n--)
	{
		char s[2];
		int t;
		scanf("%s %d", s, &t);
		if (s[0] == '+')
		{
			vis[t] = true;
			cur++;
			ans = max(ans, cur);
		}
		else
		{
			if (!vis[t])
			{
				ans++;
			}
			else
			{
				vis[t] = false;
				cur--;
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}
