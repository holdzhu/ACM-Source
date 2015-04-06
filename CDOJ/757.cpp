#include <cstdio>

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int N, M;
		scanf("%d %d", &N, &M);
		if (N % 2 || M % 2)
		{
			printf("UDK\n");
		}
		else
		{
			printf("RU\n");
		}
	}
	return 0;
}
