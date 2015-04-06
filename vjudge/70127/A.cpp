#include <cstdio>

char ans[10000];

int main()
{
	int N;
	scanf("%d", &N);
	while (N--)
	{
		char s[101];
		scanf("%s", s);
		int p = 1;
		ans[0] = s[0] - '0';
		int h = ans[0];
		for (int i = 1; s[i] != '\0'; ++i)
		{
			if (h < s[i] - '0')
			{
				h = s[i] - '0';
			}
			if (s[i] == s[i - 1])
			{
				ans[p++] = s[i] - '0';
			}
			else if (s[i] > s[i - 1])
			{
				for (int j = s[i - 1] - '0' + 1; j <= s[i] - '0'; ++j)
				{
					ans[p++] = j;
				}
			}
			else
			{
				for (int j = s[i - 1] - '0' - 1; j >= s[i] - '0'; --j)
				{
					ans[p++] = j;
				}
			}
		}
		for (int i = h; i > 0; --i)
		{
			for (int j = 0; j < p; ++j)
			{
				printf("%c", ans[j] >= i ? '+' : '*');
			}
			printf("\n");
		}
	}
	return 0;
}
