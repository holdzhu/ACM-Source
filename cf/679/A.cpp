#include <cstdio>

const int a[4] = {2, 3, 5, 7};
const int b[11] = {11, 13, 15, 17, 23, 29, 31, 37, 41, 43, 47};

char cmd[10];

int main()
{
	int cnt = 0;
	int last = 0;
	for (int i = 0; i < 4; ++i)
	{
		printf("%d\n", a[i]);
		fflush(stdout);
		scanf("%s", cmd);
		if (cmd[0] == 'y')
		{
			++cnt;
			last = i;
		}
	}
	if (cnt == 0)
		printf("prime\n");
	else if (cnt > 1)
		printf("composite\n");
	else
	{
		printf("%d\n", a[last] * a[last]);
		fflush(stdout);
		scanf("%s", cmd);
		if (cmd[0] == 'y')
			printf("composite\n");
		else
		{
			bool flag = true;
			for (int i = 0; i < 11; ++i)
			{
				printf("%d\n", b[i]);
				fflush(stdout);
				scanf("%s", cmd);
				if (cmd[0] == 'y')
				{
					flag = false;
					break;
				}
			}
			puts(flag ? "prime" : "composite");
		}
	}
	fflush(stdout);
	return 0;
}
