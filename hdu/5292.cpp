#include <cstdio>

const int add[] = {1, 2, 2, 1, 2, 1, 0, 0, 2, 1, 1, 2, 0, 0, 1, 2, 1, 2, 2, 1, 0, 0, 0, 0};

int main()
{
	int T;
	scanf("%d", &T);
	for (int kase = 1; kase <= T; ++kase)
	{
		char s[3];
		int sum = 0;
		for (int i = 0; i < 24; ++i)
		{
			scanf("%s", s);
			if (s[0] == 'r' || s[0] == 'o')
			{
				sum += add[i];
			}
		}
		printf("Case #%d: ", kase);
		if (sum % 3 == 0)
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
	return 0;
}
