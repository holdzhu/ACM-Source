#include <cstdio>

int main()
{
	int N;
	while (scanf("%d", &N) == 1 && N)
	{
		int s = 0;
		while (N--)
		{
			int t;
			scanf("%d", &t);
			s += t;
		}
		printf("%d\n", s);
	}
	return 0;
}
