#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int N, V;
		scanf("%d %d", &N, &V);
		int c[N], w[N];
		for (int i = 0; i < N; ++i)
		{
			scanf("%d", &w[i]);
		}
		for (int i = 0; i < N; ++i)
		{
			scanf("%d", &c[i]);
		}
		int f[V + 1];
		memset(f, 0, sizeof(f));
		for (int i = 0; i < N; ++i)
		{
			for (int j = V; j >= c[i]; --j)
			{
				f[j] = max(f[j], f[j - c[i]] + w[i]);
			}
		}
		printf("%d\n", f[V]);
	}
	return 0;
}
