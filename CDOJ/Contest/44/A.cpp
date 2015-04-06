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
		int o1 = 0;
		int o2 = 0;
		int l = strlen(s);
		for (int i = 0; i < l; ++i)
		{
			if (s[i] == '1')
			{
				o1++;
			}
		}
		scanf("%s", s);
		l = strlen(s);
		for (int i = 0; i < l; ++i)
		{
			if (s[i] == '1')
			{
				o2++;
			}
		}
		if (o1 % 2)
		{
			o1++;
		}
		if (o1 >= o2)
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
	return 0;
}
