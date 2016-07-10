#include <cstdio>

int main()
{
	int x;
	scanf("%d", &x);
	if (x == 3)
		return !printf("5\n");
	for (int i = 1; ; i += 2)
		if (i * i / 2 + 1 >= x)
			return !printf("%d\n", i);
}
