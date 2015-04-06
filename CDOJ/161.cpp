#include <cstdio>

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		char s[201];
		scanf("%s", s);
		int i = 0;
		bool up = false;
		int c = 0;
		while (s[i] != '\0')
		{
			if (s[i] >= 'a' && s[i] <= 'z')
			{
				if (up)
				{
					int j = i;
					while (s[j] >= 'a' && s[j] <= 'z')
					{
						j++;
					}
					if (j - i > 1)
					{
						up = !up;
					}
					c++;
					i = j - 1;
				}
			}
			else
			{
				if (!up)	
				{
					int j = i;
					while (s[j] >= 'A' && s[j] <= 'Z')
					{
						j++;
					}
					if (j - i > 1)
					{
						up = !up;
					}
					c++;
					i = j - 1;
				}
			}
			i++;
		}
		printf("%d\n", c + i);
	}
	return 0;
}
