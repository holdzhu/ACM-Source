#include <cstdio>

char s[3145730];
const char ps[] = "wyh";

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%s", s);
		int p = 0;
		for (int i = 0; s[i]; ++i)
		{
			if (s[i] == ps[p] || (s[i] == 'v' && s[i + 1] == 'v' && p == 0))
			{
				p++;
			}
			if (p == 3)
			{
				break;
			}
		}
		if (p == 3)
		{
			printf("Yes\n");
		}
		else
		{
			printf("No\n");
		}
	}
	return 0;
}
