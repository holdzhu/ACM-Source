#include <cstdio>
#include <cstring>

char s[101];
char t[101];
int l;
int tl;
int c[200];
int tc[200];
int Test = 1;

int main()
{
	while (scanf("%s", s) == 1 && s[0] != '.')
	{
		l = strlen(s);
		memset(c, 0, sizeof c);
		for (int i = 0; i < l; ++i)
		{
			c[(int)s[i]]++;
		}
		int ans = 0;
		int num;
		while (scanf("%d", &num) == 1 && num)
		{
			while (num--)
			{
				scanf("%s", t);
				tl = strlen(t);
				for (int pos = 0; pos < tl - l + 1; ++pos)
				{
					int sub = 0;
					memset(tc, 0, sizeof tc);
					for (int i = pos; i < l + pos; ++i)
					{
						if (tc[(int)t[i]] < c[(int)t[i]])
						{
							sub++;
							tc[(int)t[i]]++;
						}
						else
						{
							if (tc[(int)'_'] < c[(int)'_'])
							{
								tc[(int)'_']++;
								sub++;
							}
						}
					}
					if (sub >= l)
					{
						ans++;
						break;
					}
				}
			}
		}
		printf("Test %d: %d\n", Test++, ans);
	}
	return 0;
}
