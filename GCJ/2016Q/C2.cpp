#include <cstdio>
#include <iostream>
#include "bigN.cpp"

using namespace std;

void factor(bigN x)
{
	// cout << x << endl;
	for (int i = 2; bigN(i * i) <= x && i <= 100; ++i)
	{
		if (x % i == 0)
		// {
			printf("%d ", i);
		// 	x /= i;
		// }
	}
}

int main()
{
	for (int i = 2; i <= 10; ++i)
	{
		bigN x = 1;
		for (int j = 0; j < 31; ++j)
			x *= i;
		factor(x + bigN(1));
		printf("\n");
	}
	return 0;
}
