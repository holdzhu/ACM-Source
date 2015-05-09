#include <cstdio>

char s[3000001];
int next[3000001];

int main()
{
	scanf("%s", s);
	next[0] = -1;
	for (int i = 0; s[i]; ++i)
	{
		int t = next[i];
		while (t >= 0 && s[t] != s[i])
		{
			t = next[t];
		}
		next[i + 1] = t + 1;
	}
	int last = 0;
	for (int i = 1; s[i - 1]; ++i)
	{
		if (i > 1)
		{
			putchar(' ');
		}
		if (i % (i - next[i]))
		{
			last = i;
		}
		else
		{
			last = i - next[i];
		}
		printf("%d", last);
	}
	printf("\n%.*s\n", last, s);
	return 0;
}
