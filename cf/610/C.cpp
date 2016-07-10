#include <cstdio>
#include <algorithm>

int main()
{
	int k;
	scanf("%d", &k);
	for (int i = 0; i < (1 << k); ++i, puts(""))
		for (int j = 0; j < (1 << k); ++j)
			putchar(__builtin_parity(i & j) ? '+' : '*');
	return 0;
}
