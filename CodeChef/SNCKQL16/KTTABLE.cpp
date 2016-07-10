#include <cstdio>

int A[10001];
int B[10001];

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int N;
		scanf("%d", &N);
		for (int i = 1; i <= N; ++i)
			scanf("%d", &A[i]);
		for (int i = 1; i <= N; ++i)
			scanf("%d", &B[i]);
		int ans = 0;
		for (int i = 1; i <= N; ++i)
			ans += B[i] <= A[i] - A[i - 1];
		printf("%d\n", ans);
	}
	return 0;
}
