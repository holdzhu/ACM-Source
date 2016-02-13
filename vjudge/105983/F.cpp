#include <cstdio>

int main()
{
	int N, K;
	scanf("%d %d", &N, &K);
	int cnt = 0, mx = 0;
	for (int i = 0; i < N; ++i)
	{
		int T;
		scanf("%d", &T);
		if (T > mx)
			mx = T, cnt = 1;
		else if (T == mx)
			cnt++;
	}
	printf("%d\n", mx + (K + cnt - 2) / N + 1);
	return 0;
}
