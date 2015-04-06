#include <cstdio>
#include <cstring>

const int p[] = {1, 1, 2, 6, 24, 120, 720, 5040};

int main()
{
	int N, M;
	while (scanf("%d %d", &N, &M) == 2)
	{
		bool vis[N];
		memset(vis, 0, sizeof(vis));
		M--;
		for (int i = 0; i < N; ++i)
		{
			int ans;
			if (N - i <= 8)
			{
				int t = M / p[N - i - 1];
				M %= p[N - i - 1];
				for (int j = 0; j < N; ++j)
				{
					if (!vis[j])
					{
						t--;
					}
					if (t < 0)
					{
						ans = j;
						break;
					}
				}
			}
			else
			{
				ans = i;
			}
			if (i)
			{
				printf(" ");
			}
			printf("%d", ans + 1);
			vis[ans] = true;
		}
		printf("\n");
	}
	return 0;
}
