#include <cstdio>
#include <algorithm>

using namespace std;

int a[100000];

int main()
{
	int T;
	scanf("%d", &T);
	for (int kase = 0; kase < T; ++kase)
	{
		int N;
		scanf("%d", &N);
		for (int i = 0; i < N; ++i)
		{
			scanf("%d", &a[i]);
		}
		int L = 0;
		int R = 1000010;
		while (L < R)
		{
			int M = (L + R) >> 1;
			int lb = -1000001;
			int rb = 1000001;
			bool flag = true;
			for (int i = 0; i < N; ++i)
			{
				lb = max(lb + 1, a[i] - M);
				rb = a[i] + M;
				if (lb > rb)
				{
					flag = false;
					break;
				}
			}
			if (flag)
			{
				R = M;
			}
			else
			{
				L = M + 1;
			}
		}
		printf("Case #%d:\n%d\n", kase + 1, L);
	}
	return 0;
}
