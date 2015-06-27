#include <cstdio>
#include <cstring>

char s[103];

inline int idx(char c)
{
	return c - '0';
}

int main()
{
	s[0] = '0';
	s[1] = '0';
	scanf("%s", s + 2);
	int l = strlen(s);
	for (int i = 0; i < l; ++i)
	{
		for (int j = i + 1; j < l; ++j)
		{
			for (int k = j + 1; k < l; ++k)
			{
				int num = idx(s[i]) * 100 + idx(s[j]) * 10 + idx(s[k]);
				if (num % 8 == 0)
				{
					printf("YES\n%d\n", num);
					return 0;
				}
			}
		}
	}
	printf("NO\n");
	return 0;
}
