#include <cstdio>
#include <cstring>

int cnt[101];

int main()
{
	int n;
	while (scanf("%d", &n) == 1 && n)
	{
		memset(cnt, 0, sizeof(cnt));
		while (n--)
		{
			int t;
			scanf("%d", &t);
			cnt[t]++;
		}
		int a;
		scanf("%d", &a);
		printf("%d\n", cnt[a]);
	}
	return 0;
}
