#include <cstdio>

char s[9];

int main()
{
	int n, p;
	scanf("%d %d", &n, &p);
	long long all = 0;
	int cnt = 0;
	for (int i = 0; i < n; ++i)
	{
		scanf("%s", s);
		if (s[4])
			all |= 1ll << i, cnt++;
	}
	printf("%I64d\n", all * p - cnt * p / 2);
	return 0;
}
