#include <cstdio>
#include <cstring>

int c[26][100001];
char s[100001];
int T;
int l, r;
char ch;

int main()
{
	gets(s);
	memset(c, 0, sizeof(c));
	for (int i = 0; s[i] != '\0'; ++i)
	{
		for (int j = 0; j < 26; ++j)
		{
			c[j][i + 1] = c[j][i];
		}
		c[s[i] - 'a'][i + 1]++;
	}
	gets(s);
	sscanf(s, "%d", &T);
	while (T--)
	{
		gets(s);
		int i = 0;
		while (s[i] == ' ')
		{
			i++;
		}
		sscanf(s + i + 1, "%d %d", &l, &r);
		ch = s[i];
		if (ch >= 'a' && ch <= 'z')
		{
			printf("%d\n", c[ch - 'a'][r] - c[ch - 'a'][l - 1]);
		}
		else
		{
			printf("0\n");
		}
	}
	return 0;
}
