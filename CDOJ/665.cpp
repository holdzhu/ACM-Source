#include <cstdio>

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int k;
		scanf("%d", &k);
		int s = 1;
		for (int i = 0; i < k; ++i)
		{
			s *= 2;
		}
		printf("%d\n", s - 2);
	}
	return 0;
}
