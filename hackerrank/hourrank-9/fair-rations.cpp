#include <cstdio>

int B[1000];
int S[1000];

int main()
{
	int N;
	scanf("%d", &N);
	int sum = 0;
	for (int i = 0; i < N; ++i)
	{
		scanf("%d", &B[i]);
		sum += B[i];
	}
	if (sum & 1)
		puts("NO");
	else
	{
		int cnt = 0;
		for (int i = 0; i + 1 < N; ++i)
		{
			if (B[i] & 1)
			{
				cnt += 2;
				B[i]++;
				B[i + 1]++;
			}
		}
		printf("%d\n", cnt);
	}
	return 0;
}
