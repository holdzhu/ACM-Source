#include <cstdio>

int main()
{
	int A;
	while (scanf("%d", &A) == 1 && A)
	{
		printf("%d\n", A & (-A));
	}
	return 0;
}
