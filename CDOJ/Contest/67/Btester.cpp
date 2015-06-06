#include <cstdio>

int main()
{
	printf("1501 2000\n");
	for (int i = 0; i < 500; ++i)
	{
		if (i > 250 && i < 300)
		{
			printf("%d %d 1\n", i * 3 + 1, i * 3 + 2);
			printf("%d %d 1\n", i * 3 + 1, i * 3 + 3);
			printf("%d %d 1\n", i * 3 + 2, i * 3 + 4);
			printf("%d %d 1\n", i * 3 + 3, i * 3 + 4);
		}
		else
		{
			printf("%d %d 1\n", i * 3 + 1, i * 3 + 2);
			printf("%d %d 1\n", i * 3 + 1, i * 3 + 3);
			printf("%d %d 1\n", i * 3 + 2, i * 3 + 4);
			printf("%d %d 1\n", i * 3 + 3, i * 3 + 4);
		}
	}
	return 0;
}
