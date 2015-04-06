#include <cstdio>

int main()
{
	int n;
	while (1)
	{
		scanf("%d", &n);
		if (!n)
		{
			break;
		}
		char c;
		int R = 0;
		int Y = 0;
		for (int i = 0; i < n; ++i)
		{
			scanf(" %c", &c);
			if (c == 'R')
			{
				R++;
			}
			else if (c == 'Y')
			{
				Y++;
			}
			else
			{
				if (c == 'B')
				{
					if (R == 7)
					{
						printf("Red\n");
					}
					else
					{
						printf("Yellow\n");
					}
				}
				else
				{
					if (Y == 7)
					{
						printf("Yellow\n");
					}
					else
					{
						printf("Red\n");
					}
				}
			}
		}
	}
	return 0;
}
