#include <cstdio>

int main()
{
	int N;
	while (scanf("%d", &N) == 1 && N)
	{
		int last = 0;
		int s = 0;
		while (N--)
		{
			int t;
			scanf("%d", &t);
			if (t > last)
			{
				s += (t - last) * 6;
			}
			else
			{
				s += (last - t) * 4;
			}
			s += 5;
			last = t;
		}
		printf("%d\n", s);
	}
	return 0;
}
