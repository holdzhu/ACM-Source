#include <cstdio>
#include <cstring>

char buf[100001];

int main()
{
	int ch[26];
	while (gets(buf))
	{
		memset(ch, 0, sizeof(ch));
		for (int i = 0; buf[i] != '\0'; ++i)
		{
			if (buf[i] >= 'a' && buf[i] <= 'z')
			{
				ch[buf[i] - 'a']++;
			}
		}
		for (int i = 0; i < 26; ++i)
		{
			printf("%c:%d\n", 'a' + i, ch[i]);
		}
		printf("\n");
	}
	return 0;
}
