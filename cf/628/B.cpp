#include <cstdio>
#include <cstring>

char s[300001];

int main()
{
	scanf("%s", s);
	int l = strlen(s);
	long long ans = 0;
	for (int i = 0; i < l; ++i)
		if ((s[i] - '0') % 4 == 0)
			ans++;
	for (int i = 0; i < l - 1; ++i)
		if (((s[i] - '0') * 10 + (s[i + 1] - '0')) % 4 == 0)
			ans += i + 1;
	printf("%I64d\n", ans);
	return 0;
}
