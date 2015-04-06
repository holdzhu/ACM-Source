#include <cstdio>
#include <cmath>

int main()
{
	int L, R;
	while (scanf("%d %d", &L, &R) == 2)
	{
		printf("%d\n", (int) (R / log(R)));
	}
	return 0;
}
