#include <cstdio>

int main()
{
	int n;
	char s1[10], s2[10];
	while (scanf("%d %s %s", &n, s1, s2) == 3)
	{
		char s[9];
		int pos2 = 0;
		int pos = 0;
		for (int i = 0; i < n; ++i)
		{
			s[pos++] = s1[i];
			while (pos && s[pos - 1] == s2[pos2])
			{
				pos--;
				pos2++;
			}
		}
		if (pos2 == n)
		{
			printf("Yes.\n");
			pos2 = 0;
			for (int i = 0; i < n; ++i)
			{
				s[pos++] = s1[i];
				printf("in\n");
				while (pos && s[pos - 1] == s2[pos2])
				{
					pos--;
					pos2++;
					printf("out\n");
				}
			}
		}
		else
		{
			printf("No.\n");
		}
		printf("FINISH\n");
	}
	return 0;
}
