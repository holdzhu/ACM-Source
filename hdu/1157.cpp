#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
	int N;
	while (scanf("%d", &N) == 1)
	{
		int a[N];
		for (int i = 0; i < N; ++i)
		{
			scanf("%d", &a[i]);
		}
		sort(a, a + N);
		printf("%d\n", a[N / 2]);
	}
	return 0;
}
