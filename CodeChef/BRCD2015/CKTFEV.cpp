#include <cstdio>

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int O, R, S;
		scanf("%d%d%d", &O, &R, &S);
		printf("%.2f\n", (O * R + S) * 1.0 / (O + 1));
	}
	return 0;
}
