#include <cstdio>
#include <algorithm>

int main()
{
	int N;
	scanf("%d", &N);
	int a[N];
	for (int i = 0; i < N; ++i)
	{
		scanf("%d", &a[i]);
	}
	std::sort(a, a + N);
	printf("%d\n", a[N / 2]);
	return 0;
}
