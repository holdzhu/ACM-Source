#include <cstdio>
#include <algorithm>

using namespace std;

char s1[1001];
char s2[1001];

int main()
{
	int n;
	scanf("%d", &n);
	scanf("%s", s1);
	scanf("%s", s2);
	long long ans = 0;
	for (int i = 0; i < n; ++i)
	{
		int u = s1[i] - '0';
		int v = s2[i] - '0';
		if (u == v)
		{
			
		}
		else if (u > v)
		{
			ans += min(u - v, v + 10 - u);
		}
		else
		{
			ans += min(v - u, u + 10 - v);
		}
	}
	printf("%I64d\n", ans);
	return 0;
}
