#include <cstdio>
#include <cstring>

char s[100001], t[31];

int main()
{
	scanf("%s %s", s, t);
	int n = strlen(s);
	int m = strlen(t);
	int ans = 0;
	for (int i = 0; i < n - m + 1; ++i)
	{
		if (strncmp(s + i, t, m) == 0)
			s[i + m - 1] = '#', ans++;
	}
	printf("%d\n", ans);
	return 0;
}
