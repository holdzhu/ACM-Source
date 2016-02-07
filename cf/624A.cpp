#include <cstdio>

int main()
{
	int d, L, v1, v2;
	scanf("%d %d %d %d", &d, &L, &v1, &v2);
	printf("%.10f\n", 1.0 * (L - d) / (v1 + v2));
	return 0;
}
