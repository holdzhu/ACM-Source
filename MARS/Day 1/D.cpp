#include <cstdio>
#include <cstring>

int main()
{
	char s[200001];
	scanf("%s", s);
	int l = strlen(s);
	bool lastcouple = false;
	int lastlen = 1;
	char lastchar = s[0];
	putchar(s[0]);
	for (int i = 1; i < l; ++i)
	{
		if (s[i] == lastchar)
		{
			if (lastlen == 1)
			{
				if (lastcouple)
				{
					
				}
				else
				{
					putchar(s[i]);
					lastlen++;
				}
			}
			else if (lastlen > 1)
			{
				lastlen++;
			}
		}
		else
		{
			if (lastlen >= 2)
			{
				lastcouple = true;
			}
			else
			{
				lastcouple = false;
			}
			lastlen = 1;
			putchar(s[i]);
		}
		lastchar = s[i];
	}
	return 0;
}
