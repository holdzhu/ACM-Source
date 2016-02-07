#include <cstdio>
#include <cstring>

char s[100001];
char t[100001];

int main()
{
	t[0] = '1';
	int n;
	scanf("%d", &n);
	bool zero = false;
	int suff = 0;
	for (int i = 0; i < n; ++i)
	{
		scanf("%s", s);
		if (s[0] == '0')
			zero = true;
		else
		{
			int l = strlen(s);
			int cnt = 0;
			for (int j = 0; j < l; ++j)
				cnt += s[j] == '0';
			if (cnt == l - 1 && s[0] == '1')
				suff += cnt;
			else
				strcpy(t, s);
		}
	}
	if (zero)
		puts("0");
	else
	{
		printf("%s", t);
		for (int i = 0; i < suff; ++i)
			putchar('0');
	}
	return 0;
}
