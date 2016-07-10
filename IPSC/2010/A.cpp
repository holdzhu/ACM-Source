#include <cstdio>
#include <algorithm>

using namespace std;

int a[1000];

int main()
{
	int T;
	scanf("%d", &T);
	printf("%d\n", T);
	while (T--)
	{
		int N;
		scanf("%d", &N);
		printf("%d\n", N);
		for (int i = 0; i < N; ++i)
			scanf("%d", &a[i]);
		sort(a, a + N);
		swap(a[0], a[1]);
		for (int i = 0; i < N; ++i)
			printf("%d ", a[i]);
		puts("");
	}
	return 0;
}
