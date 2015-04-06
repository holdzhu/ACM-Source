#include <cstdio>
#include <cstring>

char s[100001];

int main()
{
	scanf("%s", s);
	bool c[26];
	int l = strlen(s);
	int q = 0;
	int fq = 0;
	memset(c, 0, sizeof(c));
	for (int i = 0; i < l; ++i)
	{
		if (s[i] == '?')
		{
			if (i > 0 && i < l - 1 && s[i - 1] == s[i + 1])
			{
				fq++;
			}
			else
			{
				q++;
			}
		}
		else
		{
			c[s[i] - 'a'] = true;
		}
	}
	if (q == 0)
	{
		for (int i = 0; i < 26; ++i)
		{
			if (c[i])
			{
				q++;
			}
		}
	}
	if (q == 1)
	{
		printf("Yes\n");
	}
	else
	{
		if ((q + fq) % 2)
		{
			printf("Yes\n");
		}
		else
		{
			printf("No\n");
		}
	}
	return 0;
}
