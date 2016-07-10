#include <cstdio>
#include <cstring>

char s[101], t[101];

int main()
{
	scanf("%s %s", s, t);
	printf("%d\n", strstr(s, t) - s + 1);
	return 0;
}
