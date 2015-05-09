#include <cstdio>
#include <cstring>
#include <cctype>

char s[201];
const char marshtomp[] = "marshtomp";
const char fjxmlhx[] = "fjxmlhx";

int main()
{
	while (gets(s))
	{
		for (int i = 0; s[i]; ++i)
		{
			int j;
			for (j = 0; j < 9 && tolower(s[i + j]) == marshtomp[j]; ++j);
			if (j == 9)
			{
				printf("%s", fjxmlhx);
				i += 8;
			}
			else
			{
				putchar(s[i]);
			}
		}
		putchar('\n');
	}
	return 0;
}
