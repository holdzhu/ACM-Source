#include <cstdio>

char s1[100001];
char s2[100001];

int main()
{
	int n, t;
	scanf("%d %d", &n, &t);
	scanf("%s %s", s1, s2);
	int cnt = 0;
	for (int i = 0; i < n; ++i)
	{
		if (s1[i] == s2[i])
		{
			cnt++;
		}
	}
	if (t < cnt)
	{
		puts("-1");
	}
	else
	{
		t -= cnt;
		for (int i = 0; i < n; ++i)
		{
			if (s1[i] == s2[i])
			{
				if (t)
				{
					putchar((s1[i] - 'a' + 1) % 26 + 'a');
				}
				else
				{
					putchar(s1[i]);
				}
			}
			else
			{
				
			}
		}
	}
	return 0;
}
