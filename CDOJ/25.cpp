#include <cstdio>
#include <cstring>

int main()
{
	int n;
	while (1)
	{
		scanf("%d", &n);
		if (n == 0)
		{
			break;
		}
		char s[101];
		bool a[n];
		gets(s);
		for (int i = 0; i < n; ++i)
		{
			gets(s);
			int l = strlen(s);
			if (l >= 10 && s[l - 8] == ' ' && s[l - 7] == 'n' && s[l - 6] == 'o' && s[l - 5] == ' ' && s[l - 4] == 'g' && s[l - 3] == 'o' && s[l - 2] == 'o' && s[l - 1] == 'd')
			{
				a[i] = false;
			}
			else
			{
				a[i] = true;
			}
		}
		for (int i = 0; i < (n + 1) / 2; ++i)
		{
			printf("%d ", i + 1);
		}
		printf("Score\n");
		int g = 0;
		for (int i = 0; i < n; i += 2)
		{
			if (a[i])
			{
				g++;
				printf("O ");
			}
			else
			{
				printf("X ");
			}
		}
		printf("%d\n", g);
		g = 0;
		for (int i = 1; i < n; i += 2)
		{
			if (a[i])
			{
				g++;
				printf("O ");
			}
			else
			{
				printf("X ");
			}
		}
		if (n % 2)
		{
			printf("- ");
		}
		printf("%d\n", g);
	}
	return 0;
}
