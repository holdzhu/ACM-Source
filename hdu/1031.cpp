#include <cstdio>
#include <cstring>
#include <algorithm>
#include <functional>

using namespace std;

int p[1000000];
double s[1000000];

bool cmp(const int a, const int b)
{
	return s[a] > s[b] || (s[a] == s[b] && a < b);
}

int main()
{
	int N, M, K;
	while (scanf("%d %d %d", &N, &M, &K) == 3)
	{
		memset(s, 0, sizeof(s));
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < M; ++j)
			{
				double t;
				scanf("%lf", &t);
				s[j] += t;
			}
		}
		for (int i = 0; i < M; ++i)
		{
			p[i] = i;
		}
		sort(p, p + M, cmp);
		sort(p, p + K, greater<int>());
		for (int i = 0; i < K; ++i)
		{
			if (i)
			{
				printf(" ");
			}
			printf("%d", p[i] + 1);
		}
		printf("\n");
	}
	return 0;
}
