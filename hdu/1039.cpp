#include <cstdio>

bool isvowel(char c)
{
	return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

int main()
{
	char s[21];
	while (scanf("%s", s) == 1 && !(s[0] == 'e' && s[1] == 'n' && s[2] == 'd' && s[3] == '\0'))
	{
		bool hasvowel = false;
		bool flag = true;
		for (int i = 0; s[i] != '\0'; ++i)
		{
			if (isvowel(s[i]))
			{
				hasvowel = true;
			}
			if (i >= 2 && isvowel(s[i]) == isvowel(s[i - 1]) && isvowel(s[i]) == isvowel(s[i - 2]))
			{
				flag = false;
				break;
			}
			if (i >= 1 && s[i] == s[i - 1] && s[i] != 'e' && s[i] != 'o')
			{
				flag = false;
				break;
			}
		}
		if (hasvowel && flag)
		{
			printf("<%s> is acceptable.\n", s);
		}
		else
		{
			printf("<%s> is not acceptable.\n", s);
		}
	}
	return 0;
}
