#include <cstdio>
#include <cstring>

char t[100][101];
int len[100];
char s[101];
bool kase[101];
bool change[101];

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%s", t[i]);
		len[i] = strlen(t[i]);
		for (int j = 0; j < len[i]; ++j)
			if (t[i][j] <= 'Z')
				t[i][j] += 'z' - 'Z';
	}
	scanf("%s", s);
	int l = strlen(s);
	for (int i = 0; i < l; ++i)
		if (s[i] <= 'Z')
			s[i] += 'z' - 'Z', kase[i] = 1;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j <= l - len[i]; ++j)
			if (strncmp(t[i], s + j, len[i]) == 0)
				for (int k = j; k < j + len[i]; ++k)
					change[k] = 1;
	char luck;
	scanf(" %c", &luck);
	for (int i = 0; i < l; ++i)
		if (change[i])
			s[i] = s[i] == luck ? (luck == 'a' ? 'b' : 'a') : luck;
	for (int i = 0; i < l; ++i)
		putchar(kase[i] ? s[i] - 'a' + 'A' : s[i]);
	puts("");
	return 0;
}
