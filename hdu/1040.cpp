#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int N;
		scanf("%d", &N);
		int a[N];
		for (int i = 0; i < N; ++i)
		{
			scanf("%d", &a[i]);
		}
		sort(a, a + N);
		for (int i = 0; i < N; ++i)
		{
			if (i)
			{
				printf(" ");
			}
			printf("%d", a[i]);
		}
		printf("\n");
	}
	return 0;
}
