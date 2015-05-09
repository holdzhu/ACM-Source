#include <cstdio>
#include <cstring>

int n[2];
char s[2][101];

int main()
{
	int Test = 1;
	while (scanf("%s", s[0]) == 1 && !(s[0][0] == '0' && s[0][1] == 0))
	{
		int cur = 0;
		n[cur] = strlen(s[cur]);
		while (1)
		{
			if (n[cur] % 2 == 1)
			{
				break;
			}
			n[1 - cur] = 0;
			for (int i = 0; i < n[cur]; i += 2)
			{
				for (int j = 0; j < s[cur][i] - '0'; ++j)
				{
					s[1 - cur][n[1 - cur]++] = s[cur][i + 1];
				}
			}
			s[1 - cur][n[1 - cur]] = 0;
			cur = 1 - cur;
			if (strcmp(s[cur], s[1 - cur]) == 0)
			{
				break;
			}
		}
		printf("Test %d: %s\n", Test++, s[cur]);
	}
	return 0;
}
