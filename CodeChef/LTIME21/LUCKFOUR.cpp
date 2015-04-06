#include <cstdio>

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		char s[100];
		scanf("%s", s);
		int c = 0;
		for (int i = 0; s[i] != '\0'; ++i)
		{
			if (s[i] == '4')
			{
				c++;
			}
		}
		printf("%d\n", c);
	}
	return 0;
}
