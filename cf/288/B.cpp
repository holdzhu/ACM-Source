#include <cstdio>
#include <cstring>

int main()
{
	char s[100001];
	scanf("%s", s);
	int l = strlen(s);
	int last = -1;
	for (int i = 0; i < l - 1; ++i)
	{
		if ((s[i] - '0') % 2 == 0)
		{
			last = i;
			if (s[i] < s[l - 1])
			{
				break;
			}
		}
	}
	if (last >= 0)
	{
		char t = s[l - 1];
		s[l - 1] = s[last];
		s[last] = t;
		printf("%s\n", s);
	}
	else
	{
		printf("-1\n");
	}
	return 0;
}
