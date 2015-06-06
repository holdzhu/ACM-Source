#include <cstdio>
#include <cstring>

int in[100000];

int main()
{
	int N, M;
	while (scanf("%d %d", &N, &M) == 2)
	{
		memset(in, 0, sizeof in);
		for (int i = 0; i < M; ++i)
		{
			int u, v;
			scanf("%d %d", &u, &v);
			u--;
			v--;
			in[u]++;
			in[v]++;
		}
		int cnt = 0;
		for (int i = 0; i < N; ++i)
		{
			if (in[i] == 1)
			{
				cnt++;
			}
		}
		printf("%d\n", (cnt + 1) / 2);
	}
	return 0;
}
