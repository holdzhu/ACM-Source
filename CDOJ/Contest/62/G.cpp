#include <cstdio>
#include <cstring>

const char ss[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ_.";
const int mod = 28;
char s[100];

int find(char c)
{
	for (int i = 0; i < mod; ++i)
	{
		if (c == ss[i])
		{
			return i;
		}
	}
	return -1;
}

int main()
{
	int N;
	while (scanf("%d", &N) == 1 && N)
	{
		scanf("%s", s);
		int l = strlen(s);
		for (int i = 0; i < l; ++i)
		{
			s[i] = ss[(find(s[i]) + N) % mod];
		}
		for (int i = 0; i < l; ++i)
		{
			printf("%c", s[l - 1 - i]);
		}
		printf("\n");
	}
	return 0;
}
