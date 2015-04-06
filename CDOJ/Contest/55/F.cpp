#include <cstdio>
#include <cstring>

const char cc[] = "Captain_Chen";

int main()
{
	int N, M, K;
	scanf("%d %d %d", &N, &M, &K);
	int acpos[M];
	bool iscc[K];
	memset(acpos, -1, sizeof(acpos));
	for (int i = 0; i < K; ++i)
	{
		char s1[21];
		scanf("%s", s1);
		iscc[i] = strcmp(s1, cc) == 0;
		if (i < K - 1)
		{
			char s2[5];
			scanf("%s", s2);
			if (s2[2] == 'A' && acpos[s2[0] - 'A'] == -1)
			{
				acpos[s2[0] - 'A'] = i;
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < K; ++i)
	{
		int sum = 0;
		for (int j = 0; j < M; ++j)
		{
			if (acpos[j] >= 0)
			{
				if ((acpos[j] >= i && iscc[acpos[j] + 1]) || (acpos[j] < i && iscc[acpos[j]]))
				{
					sum++;
				}
			}
		}
		if (ans < sum)
		{
			ans = sum;
		}
	}
	printf("%d\n", ans);
	return 0;
}
