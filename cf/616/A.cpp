#include <cstdio>
#include <cstring>

char s[1000001], t[1000001];

int main()
{
	scanf("%s %s", s, t);
	int n = 0, m = 0;
	while (s[n] == '0')
		n++;
	while (t[m] == '0')
		m++;
	int l1 = strlen(s + n);
	int l2 = strlen(t + m);
	if (l1 < l2)
		puts("<");
	else if (l1 > l2)
		puts(">");
	else
	{
		int cmp = strcmp(s + n, t + m);
		puts(cmp > 0 ? ">" : cmp == 0 ? "=" : "<");
	}
	return 0;
}
