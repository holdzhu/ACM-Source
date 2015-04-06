#include <cstdio>
#include <cstring>

int main()
{
	char s[10001];
	int N;
	scanf("%d", &N);
	while (N--)
	{
		scanf("%s", s);
		int l = strlen(s);
		int n = 1;
		for (int i = 1; i <= l; ++i)
		{
			if (i == l || s[i] != s[i - 1])
			{
				if (n > 1)
				{
					printf("%d", n);
				}
				printf("%c", s[i - 1]);
				n = 1;
			}
			else
			{
				n++;
			}
		}
		printf("\n");
	}
	return 0;
}
