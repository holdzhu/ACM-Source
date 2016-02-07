#include <cstdio>

int a[1000];
int c;

int main()
{
	int n;
	scanf("%d", &n);
	int p = 0;
	while (n)
	{
		p++;
		if (n & 1)
		{
			a[c++] = p;
		}
		n >>= 1;
	}
	for (int i = c - 1; i >= 0; --i)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
	return 0;
}
