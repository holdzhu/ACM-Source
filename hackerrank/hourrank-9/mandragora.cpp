#include <cstdio>
#include <algorithm>

using namespace std;

int H[100000];
long long sum[100001];

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int N;
		scanf("%d", &N);
		for (int i = 0; i < N; ++i)
			scanf("%d", &H[i]);
		sort(H, H + N);
		for (int i = 0; i < N; ++i)
			sum[i + 1] = sum[i] + H[i];
		long long ans = sum[N];
		for (int i = 0; i < N; ++i)
			ans = max(ans, (i + 1) * (sum[N] - sum[i]));
		printf("%lld\n", ans);
	}
	return 0;
}
