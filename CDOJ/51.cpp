#include <cstdio>
#include <cstring>

int RM;
double P[20];
double N;
double CP;
double MAXP;

void DFS(int pos)
{
	if (pos < RM)
	{
		if (CP + P[pos] <= N)
		{
			CP += P[pos];
			DFS(pos + 1);
			CP -= P[pos];
		}
		DFS(pos + 1);
	}
	else
	{
		if (CP > MAXP)
		{
			MAXP = CP;
		}
	}
}

int main()
{
	const char NON[4][7] = {"spicy", "sugar", "pepper", "duck"};
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int M;
		scanf("%lf %d", &N, &M);
		char S[21];
		RM = 0;
		while (M--)
		{
			scanf("%s", S);
			bool b = true;
			double t;
			scanf("%lf", &t);
			for (int i = 0; i < 4; ++i)
			{
				if (strstr(S, NON[i]))
				{
					b = false;
					break;
				}
			}
			if (b)
			{
				P[RM++] = t;
			}
		}
		CP = 0;
		MAXP = 0;
		DFS(0);
		printf("%.2f\n", MAXP);
	}
	return 0;
}
