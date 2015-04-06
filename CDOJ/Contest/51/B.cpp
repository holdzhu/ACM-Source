#include <cstdio>

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int N, M;
		scanf("%d %d", &N, &M);
		int dp1 = 0;
		int dp2 = 0;
		int hp1 = 0;
		int hp2 = 0;
		int d[M], h[M];
		for (int i = 0; i < M; ++i)
		{
			scanf("%d", &d[i]);
		}
		for (int i = 0; i < M; ++i)
		{
			scanf("%d", &h[i]);
		}
		int win = 0;
		for (int i = 0; i < M; ++i)
		{
			if (dp1 >= N)
			{
				if (dp2)
				{
					dp2 += d[i];
					if (dp2 >= N)
					{
						win = 1;
						break;
					}
					if (dp2 == hp1)
					{
						hp1 = 0;
					}
					else if (dp2 == hp2)
					{
						hp2 = 0;
					}
				}
				else if (d[i] ==6)
				{
					dp2 = 1;
				}
			}
			else
			{
				if (dp1)
				{
					dp1 += d[i];
					if (dp1 < N)
					{
						if (dp1 == hp1)
						{
							hp1 = 0;
						}
						else if (dp1 == hp2)
						{
							hp2 = 0;
						}
					}
				}
				else if (d[i] ==6)
				{
					dp1 = 1;
				}
			}
			if (hp1 >= N)
			{
				if (hp2)
				{
					hp2 += h[i];
					if (hp2 >= N)
					{
						win = 2;
						break;
					}
					if (hp2 == dp1)
					{
						dp1 = 0;
					}
					else if (hp2 == dp2)
					{
						dp2 = 0;
					}
				}
				else if (h[i] ==6)
				{
					hp2 = 1;
				}
			}
			else
			{
				if (hp1)
				{
					hp1 += h[i];
					if (hp1 < N)
					{
						if (hp1 == dp1)
						{
							dp1 = 0;
						}
						else if (hp1 == dp2)
						{
							dp2 = 0;
						}
					}
				}
				else if (h[i] ==6)
				{
					hp1 = 1;
				}
			}
		}
		if (win == 1)
		{
			printf("Ye.Dong\n");
		}
		else if (win == 2)
		{
			printf("Ye.Han\n");
		}
		else
		{
			printf("Tie.\n");
		}
	}
	return 0;
}
