#include <cstdio>

int main()
{
	long long zero[1000];
	long long one[1000];
	zero[0] = 0;
	one[0] = 0;
	for (int i = 1; i < 100; ++i)
	{
		one[i] = one[i - 1] + zero[i - 1];
		zero[i] = zero[i - 1] + one[i - 1] + i % 2;
		printf("%lld\n", zero[i]);
	}
	return 0;
}
