#include <cstdio>
#include <cstring>

char s[4000000];

int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%s", s);
		int len = strlen(s);
		int ok = 0;
		int f;
		for (f = 0; f < len; f++)
		{
			if (s[f] == 'w' || (f < len - 1 && s[f] == 'v' && s[f + 1] == 'v'))break;
		}
		for (; f < len; f++)
		{
			if (s[f] == 'y')break;
		}
		for (; f < len; f++)
		{
			if (s[f] == 'h')
			{
				ok = 1;
				break;
			}
		}
		if (ok)
		{
			printf("Yes\n");
		}
	}
	return 0;
}
