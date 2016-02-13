#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

char s[100005];
int four[100005];
int seven[100005];

int main()
{
	scanf("%s", s);
	int l = strlen(s);
	for (int i = l - 1; i >= 0; --i)
	{
		four[i] = four[i + 1] + (s[l - i - 1] == '4');
		seven[i] = seven[i + 1] + (s[l - i - 1] == '7');
	}
	if (four[0] == seven[0] && four[0] + seven[0] == l)
	{
		puts(s);
		return 0;
	}
	for (int i = 1; i <= l + 1; ++i)
	{
		if (i == l + 1)
		{
			for (int i = 0; i <= l / 2; ++i)
				putchar('4');
			for (int i = 0; i <= l / 2; ++i)
				putchar('7');
			puts("");
			break;
		}
		if (four[i] + seven[i] == l - i && s[l - i] < '4' && abs(seven[i] - four[i] - 1) <= i - 1 && l % 2 == 0)
		{
			for (int j = 0; j < l - i; ++j)
				putchar(s[j]);
			for (int j = 0; j < l / 2 - four[i]; ++j)
				putchar('4');
			for (int j = 0; j < l / 2 - seven[i]; ++j)
				putchar('7');
			puts("");
			break;
		}
		if (four[i] + seven[i] == l - i && s[l - i] < '7' && abs(seven[i] - four[i] + 1) <= i - 1 && l % 2 == 0)
		{
			for (int j = 0; j < l - i; ++j)
				putchar(s[j]);
			putchar('7');
			for (int j = 0; j < l / 2 - four[i]; ++j)
				putchar('4');
			for (int j = 0; j < l / 2 - seven[i] - 1; ++j)
				putchar('7');
			puts("");
			break;
		}
	}
	return 0;
}
