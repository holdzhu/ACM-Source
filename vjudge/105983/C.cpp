#include <cstdio>

int main()
{
	long long p1, p2;
	scanf("%I64d %I64d", &p1, &p2);
	if (p1 == p2 && p1 == 0)
		puts("0 0");
	else for (int i = 3; ; ++i)
	{
		long long p3 = p1 - p2;
		p1 = p2;
		p2 = p3;
		if (p2 < 0)
		{
			printf("%d %I64d\n", i, p2);
			break;
		}
	}
	return 0;
}
