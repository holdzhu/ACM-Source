#include <cstdio>

int main()
{
	int N;
	scanf("%d", &N);
	while (N--)
	{
		int M;
		scanf("%d", &M);
		int s = 0;
		while (M--)
		{
			int t;
			scanf("%d", &t);
			s += t;
		}
		printf("%d\n", s);
		if (N)
		{
			printf("\n");
		}
	}
	return 0;
}
