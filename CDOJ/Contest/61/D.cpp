#include <cstdio>
#include <algorithm>

using namespace std;

int a[100000];
int tmp[1000000];
int top;

int main()
{
	int N;
	while (scanf("%d", &N) == 1)
	{
		int L[N];
		int R[N];
		int ans[N];
		for (int i = 0; i < N; ++i)
		{
			scanf("%d", &a[i]);
			L[i] = 0;
			R[i] = N - i - 2;
		}
		sort(a, a + N);
		long long target = ((long long)N * (N - 1) / 2 - 1) / 2;
		while (R[0] - L[0] > 0)
		{
			int M = (L[0] + R[0] + 1) >> 1;
			printf("L[0]=%d R[0]=%d M=%d\n", L[0], R[0], M);
			long long sum = M;
			for (int i = 1; i < N - 1; ++i)
			{
				if (a[i + L[i] + 1] - a[i] >= a[M + 1] - a[0])
				{
					L[i] = -1;
				}
				else while (R[i] - L[i] > 0)
				{
					int Mi = (L[i] + R[i] + 1) >> 1;
					printf("L[%d]=%d R[%d]=%d Mi=%d\n", i, L[i], i, R[i], Mi);
					if (a[i + Mi + 1] - a[i] >= a[M + 1] - a[0])
					{
						printf("road1\n");
						R[i] = Mi - 1;
					}
					else
					{
						printf("road2\n");
						L[i] = Mi;
					}
				}
				ans[i] = L[i];
				printf("ans[%d]=%d\n", i, ans[i]);
				sum += L[i] + 1;
			}
			if (sum >= target)
			{
				R[0] = M - 1;
				for (int i = 1; i < N - 1; ++i)
				{
					L[i] = 0;
				}
			}
			else
			{
				L[0] = M;
				for (int i = 1; i < N - 1; ++i)
				{
					R[i] = N - i - 2;
				}
			}
			printf("%lld %lld!!!!\n", sum, target);
		}
		long long sum = L[0] + 1;
		top = 0;
		for (int i = 1; i < N - 1; ++i)
		{
			L[i] = 0;
			R[i] = N - i - 2;
		}
		for (int i = 1; i < N - 1; ++i)
		{
			if (a[i + L[i] + 1] - a[i] >= a[L[0] + 1] - a[0])
			{
				L[i] = -1;
			}
			else while (R[i] - L[i] > 0)
			{
				int Mi = (L[i] + R[i] + 1) >> 1;
				if (a[i + Mi + 1] - a[i] >= a[L[0] + 1] - a[0])
				{
					R[i] = Mi - 1;
				}
				else
				{
					L[i] = Mi;
				}
			}
			ans[i] = L[i];
			sum += ans[i] + 1;
		}
		for (int i = 1; i < N - 1; ++i)
		{
			L[i] = 0;
			R[i] = N - i - 2;
		}
		for (int i = 1; i < N - 1; ++i)
		{
			if (a[i + L[i] + 1] - a[i] >= a[L[0] + 2] - a[0])
			{
				L[i] = -1;
			}
			else while (R[i] - L[i] > 0)
			{
				int Mi = (L[i] + R[i] + 1) >> 1;
				if (a[i + Mi + 1] - a[i] >= a[L[0] + 2] - a[0])
				{
					R[i] = Mi - 1;
				}
				else
				{
					L[i] = Mi;
				}
			}
			printf("%d %d %d\n", i, ans[i], L[i]);
			if (ans[i] < L[i]) for (int j = ans[i] + 1; j <= L[i]; ++j)
			{
				tmp[top++] = a[i + j + 1] - a[i];
			}
		}
		printf("%lld %lld %d\n", target, sum, L[0]);
		sort(tmp, tmp + top);
		printf("%d\n", tmp[target - sum]);
	}
	return 0;
}
