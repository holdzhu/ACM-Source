#include <cstdio>

int main()
{
	char s[101];
	scanf("%s", s);
	for (int i = 0; s[i]; ++i)
	{
		if (s[i] <= 'Z')
			s[i] += 'a' - 'A';
		if (s[i] != 'a' && s[i] != 'o' && s[i] != 'y' && s[i] != 'e' && s[i] != 'u' && s[i] != 'i')
			putchar('.'), putchar(s[i]);
	}
	return 0;
}
