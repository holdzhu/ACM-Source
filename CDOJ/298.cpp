#include <cstdio>
#include <cstring>

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		char s[20];
		scanf("%s", s);
		int l = strlen(s);
		int n = (l - 1) / 3;
		for (int i = 0; i < l - n * 3; ++i)
		{
			putchar(s[i]);
		}
		for (int i = l - n * 3; i < l; i += 3)
		{
			printf(",%c%c%c", s[i], s[i + 1], s[i + 2]);
		}
		printf("\n");
	}
	return 0;
}
