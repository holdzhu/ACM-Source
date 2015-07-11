#include <cstdio>
#include <cstring>

char s[100001];
int cnt[200001];

long long fz(int l, int r)
{
	if (l == r)
	{
		return 0;
	}
	int m = (l + r) >> 1;
	long long res = fz(l, m) + fz(m + 1, r);
	int t = 0;
	for (int i = m; i >= l; --i)
	{
		if (s[i] == '(')
		{
			t++;
		}
		else
		{
			t--;
		}
		cnt[100000 + t]++;
	}
	t = 0;
	for (int i = m + 1; i <= r; ++i)
	{
		if (s[i] == '(')
		{
			t++;
		}
		else
		{
			t--;
		}
		res += cnt[100000 - t];
	}
	for (int i = 100000 - (m - l + 3); i <= 100000 + (r - m + 3); ++i)
	{
		cnt[i] = 0;
	}
	return res;
}

int main()
{
	scanf("%s", s);
	int n = strlen(s);
	memset(cnt, 0, sizeof cnt);
	if (n == 2)
	{
		printf("0\n");
	}
	else
	{
		printf("%lld\n", fz(1, n - 2));
	}
	return 0;
}
