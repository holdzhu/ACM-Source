#include <cstdio>
#include <cstring>

char G[100][51];
char B[51];

int main()
{
	int T;
	scanf("%d", &T);
	for (int kase = 1; kase <= T; ++kase)
	{
		int N, L;
		scanf("%d %d", &N, &L);
		for (int i = 0; i < N; ++i)
			scanf("%s", G[i]);
		scanf("%s", B);
		bool possible = true;
		for (int i = 0; i < N; ++i)
			if (strcmp(G[i], B) == 0)
				possible = false;
		printf("Case #%d: ", kase);
		if (!possible)
			puts("IMPOSSIBLE");
		else if (L == 1)
			puts("0 ?");
		else
		{
			printf("10?");
			for (int i = 0; i < 50; ++i)
				printf("10");
			putchar(' ');
			for (int i = 0; i < L - 1; ++i)
				putchar('?');
			puts("");
		}
	}
	return 0;
}
