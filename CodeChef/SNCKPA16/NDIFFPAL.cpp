#include <cstdio>

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int N;
		scanf("%d", &N);
		for (int i = 0; i < N; ++i)
			putchar('a' + i % 3);
		puts("");
	}
	return 0;
}
