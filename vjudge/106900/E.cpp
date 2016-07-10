#include <cstdio>

char s[100001];

int main()
{
	freopen("energy.in", "r", stdin);
	freopen("energy.out", "w", stdout);
	int n;
	scanf("%d", &n);
	long long ans = 0;
	int cnt1 = 0, cnt2 = 0;
	scanf("%s", s);
	for (int i = 0; s[i]; ++i)
	{
		if (s[i] == '1')
		{
			if (cnt1 + cnt2 + cnt2 < n)
				cnt1++;
			else if (cnt2)
				cnt1++, cnt2--;
		}
		else
		{
			if (cnt1 + cnt2 + cnt2 + 1 < n)
				cnt2++;
		}
		ans += cnt1 + cnt2;
	}
	printf("%I64d\n", ans);
	return 0;
}
