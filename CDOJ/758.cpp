#include <cstdio>

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int x, y, t;
		scanf("%d %d %d", &x, &y, &t);
		char s[t + 1];
		int U = 0;
		int D = 0;
		int L = 0;
		int R = 0;
		scanf("%s", s);
		int r = -1;
		if (x == 0 && y == 0)
		{
			printf("0\n");
		}
		else
		{
			for (int i = 0; i < t; ++i)
			{
				if (s[i] == 'U')
				{
					U++;
				}
				else if (s[i] == 'D')
				{
					D++;
				}
				else if (s[i] == 'L')
				{
					L++;
				}
				else
				{
					R++;
				}
				if (((x >= 0 && R >= x) || (x < 0 && L >= -x)) && ((y >= 0 && U >= y) || (y < 0 && D >= -y)))
				{
					r = i + 1;
					break;
				}
			}
			printf("%d\n", r);
		}
	}
	return 0;
}
