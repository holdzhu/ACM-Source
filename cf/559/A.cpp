#include <cstdio>

int main()
{
	int a[6];
	for (int i = 0; i < 6; ++i)
	{
		scanf("%d", &a[i]);
	}
	long long sum = 0;
	long long cur = a[0] * 2 - 1;
	for (int i = 0; i < a[1] + a[2]; ++i)
	{
		if (i < a[5])
		{
			cur++;
		}
		else if (i > a[5])
		{
			cur--;
		}
		if (i < a[1])
		{
			cur++;
		}
		else if (i > a[1])
		{
			cur--;
		}
		sum += cur;
	}
	printf("%I64d\n", sum);
	return 0;
}
