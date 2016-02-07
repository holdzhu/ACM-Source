#include <cstdio>
#include <cstring>

char s[101];

int main()
{
	int n;
	scanf("%d", &n);
	while (n--)
	{
		scanf("%s", s);
		int l = strlen(s);
		if (l <= 10)
			puts(s);
		else
			printf("%c%d%c\n", s[0], l - 2, s[l - 1]);
	}
	return 0;
}
