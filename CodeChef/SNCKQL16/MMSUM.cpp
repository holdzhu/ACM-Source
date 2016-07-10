#include <cstdio>
#include <algorithm>

using namespace std;

int A[100000];
long long sum[100001];
long long mi[100001];
long long mx[100001];

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int N;
		scanf("%d", &N);
		int upper = -1e9;
		for (int i = 0; i < N; ++i)
		{
			scanf("%d", &A[i]);
			sum[i + 1] = sum[i] + A[i];
			upper = max(upper, A[i]);
		}
		if (upper < 0)
		{
			printf("%d\n", upper);
			continue;
		}
		mi[0] = 0;
		for (int i = 0; i < N; ++i)
			mi[i + 1] = min(mi[i], sum[i + 1]);
		mx[N] = sum[N];
		for (int i = N - 1; i >= 0; --i)
			mx[i] = max(mx[i + 1], sum[i]);
		long long ans = 0;
		for (int i = 0; i < N; ++i)
			ans = max(ans, mx[i + 1] - mi[i] + max(-A[i], 0));
		printf("%lld\n", ans);
	}
	return 0;
}
