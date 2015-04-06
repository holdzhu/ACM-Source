#include <cstdio>
#include <cctype>
#include <cstring>

char s[1000];
int c[10000000];
int d[26] = {2, 2, 2, 3, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6, 7, 7, 7, 7, 8, 8, 8, 9, 9, 9, 9};

int main()
{
	int T;
	scanf("%d ", &T);
	memset(c, 0, sizeof(c));
	while (T--)
	{
		gets(s);
		int p = 0;
		int n = 0;
		for (int i = 0; p < 7; ++i)
		{
			if (isdigit(s[i]))
			{
				n *= 10;
				n += s[i] - '0';
				++p;
			}
			else if (isupper(s[i]))
			{
				n *= 10;
				n += d[s[i] - 'A'];
				++p;
			}
		}
		c[n]++;
	}
	bool flag = true;
	for (int i = 0; i < 10000000; ++i)
	{
		if (c[i] > 1)
		{
			printf("%03d-%04d %d\n", i / 10000, i % 10000, c[i]);
			flag = false;
		}
	}
	if (flag)
	{
		printf("No duplicates.\n");
	}
	return 0;
}
