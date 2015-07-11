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
		int count0 = 0;
		int count1 = 0;
		for (int i = 0; i < N; ++i)
		{
			if (in[i] == 1)
			{
				count1++;
			}
			else if (in[i] == 0)
			{
				count0++;
			}
		}
		int ans = 0;
		if (count1 > 2)
		{
			ans = (count1 - 1) / 2;
			count1 -= ans * 2;
		}
		if (count0)
		{
			ans += count0 + 1;
		}
		else if (count1 > 0)
		{
			ans++;
		}
		printf("%d\n", ans);
	}
	return 0;
}
