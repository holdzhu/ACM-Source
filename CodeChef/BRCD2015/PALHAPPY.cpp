#include <cstdio>
#include <cstring>

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		char s[1001];
		scanf("%s", s);
		int l = strlen(s);
		int c = 0;
		for (int i = 0; i < l / 2; ++i)
		{
			if (s[i] != s[l - 1 - i])
			{
				c++;
				if (c > 1)
				{
					break;
				}
			}
		}
		if (c > 1)
		{
			printf("no\n");
		}
		else
		{
			printf("yes\n");
		}
	}
	return 0;
}
