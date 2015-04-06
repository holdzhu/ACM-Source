#include <cstdio>
#include <cstring>

char s[1001];

int main()
{
	int T;
	scanf("%d", &T);
	getchar();
	while (T--)
	{
		gets(s);
		char t[1001];
		int p = 0;
		for (int i = 0; s[i] != '\0'; ++i)
		{
			if (s[i] != ' ')
			{
				t[p++] = s[i];
			}
			else
			{
				if (p)
				{
					for (int i = 0; i < p / 2; ++i)
					{
						char c = t[i];
						t[i] = t[p - i - 1];
						t[p - i - 1] = c;
					}
					t[p] = '\0';
					p = 0;
					printf("%s", t);
				}
				printf(" ");
			}
		}
		if (p)
		{
			for (int i = 0; i < p / 2; ++i)
			{
				char c = t[i];
				t[i] = t[p - i - 1];
				t[p - i - 1] = c;
			}
			t[p] = '\0';
			printf("%s", t);
		}
		printf("\n");
	}
	return 0;
}
