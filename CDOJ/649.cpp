#include <cstdio>
#include <cstring>

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		char s[1001];
		scanf("%s", s);
		int l = strlen(s);
		int q = 0;
		for (int i = 0; i < l; ++i)
		{
			if (s[i] == '(')
			{
				q++;
			}
			else if (s[i] == ')')
			{
				q--;
				if (q < 0)
				{
					break;
				}
			}
		}
		if (q == 0)
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
