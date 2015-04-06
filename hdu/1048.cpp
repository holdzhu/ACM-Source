#include <cstdio>
#include <cstring>
#include <cctype>

int main()
{
	char s[01000];
	while (gets(s) && strcmp(s, "ENDOFINPUT"))
	{
		if (strcmp(s, "START") && strcmp(s, "END"))
		{
			for (int i = 0; s[i] != '\0'; ++i)
			{
				if (isalpha(s[i]))
				{
					s[i] = (s[i] - 'A' + 21) % 26 + 'A';
				}
			}
			printf("%s\n", s);
		}
	}
	return 0;
}
