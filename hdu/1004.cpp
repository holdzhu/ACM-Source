#include <cstdio>
#include <cstring>

int main()
{
	int N;
	while (scanf("%d", &N) == 1 && N)
	{
		char color[1000][16];
		int count[1000];
		int num = 0;
		int max = 0;
		char s[16];
		while (N--)
		{
			scanf("%s", s);
			int flag = -1;
			for (int i = 0; i < num; ++i)
			{
				if (strcmp(s, color[i]) == 0)
				{
					flag = i;
					break;
				}
			}
			if (flag >= 0)
			{
				count[flag]++;
				if (count[flag] > count[max])
				{
					max = flag;
				}
			}
			else
			{
				count[num] = 0;
				strcpy(color[num++], s);
			}
		}
		printf("%s\n", color[max]);
	}
	return 0;
}
