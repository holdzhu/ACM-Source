#include <cstdio>

int gcd(int a, int b)
{
	return b ? gcd(b, a % b) : a;
}

int main()
{
	int N, M;
	scanf("%d %d", &N, &M);
	bool flag = false;
	for (int i = 0; i < M; ++i)
	{
		int t;
		scanf("%d", &t);
		if (gcd(t, N) == 1)
		{
			flag = true;
		}
	}
	if (flag)
	{
		printf("Yes\n");
	}
	else
	{
		
	}
	return 0;
}
