#include <cstdio>
#include <cstring>
#include <cctype>

char t[1000][1000];
int pt1[1000];
int pt2[1000];
int len[1000];
char s[1000];

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		scanf(" ");
		int c = 0;
		while (1)
		{
			if (gets(s) == 0)
				break;
			if (s[0] == 0)
				break;
			int pos = 0;
			for (; !isdigit(s[pos]); ++pos);
			sscanf(s + pos, "%d %d", &pt1[c], &pt2[c]);
			strncpy(t[c], s, pos - 1);
			len[c] = pos - 1;
			c++;
		}
		while (1)
		{
			if (gets(s) == 0)
				break;
			if (s[0] == 0)
				break;
			int pos = 0;
			for (; !isdigit(s[pos]); ++pos);
			int l = pos - 1;
			int p;
			sscanf(s + pos, "%d", &p);
			for (; isdigit(s[pos]) || s[pos] == ' '; ++pos);
			for (int j = 0; j < c; ++j)
			{
				if (strncmp(t[j], s + pos, len[j]) == 0)
				{
					if (p < pt2[j])
					{
						printf("Refused %.*s %d\n", l, s, p);
					}
					else
					{
						printf("Accepted %.*s %d\n", l, s, p + pt1[j]);
					}
					break;
				}
			}
		}
		if (T)
			puts("");
	}
	return 0;
}
