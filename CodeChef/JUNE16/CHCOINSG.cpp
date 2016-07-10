#include <cstdio>

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int N;
		scanf("%d", &N);
		puts(N % 6 ? "Chef" : "Misha");
	}
	return 0;
}
