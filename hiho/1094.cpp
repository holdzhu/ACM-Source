#include <cstdio>

int N, M;
char s[200][201];
char t[3][4];

int main()
{
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; ++i)
	{
		scanf("%s", s[i]);
	}
	for (int i = 0; i < 3; ++i)
	{
		scanf("%s", t[i]);
	}
	for (int i = 0; i < N - 2; ++i)
	{
		for (int j = 0; j < M - 2; ++j)
		{
			if (s[i + 1][j + 1] == t[1][1])
			{
				bool skip = false;
				for (int k = 0; k < 4; ++k)
				{
					bool flag = true;
					for (int x = 0; x < 3 && flag; ++x)
					{
						for (int y = 0; y < 3 && flag; ++y)
						{
							if (s[i + x][j + y] != t[x][y])
							{
								flag = false;
							}
						}
					}
					if (flag && !skip)
					{
						printf("%d %d\n", i + 2, j + 2);
						skip = true;
					}
					int tmp = t[0][0];
					t[0][0] = t[0][2];
					t[0][2] = t[2][2];
					t[2][2] = t[2][0];
					t[2][0] = tmp;
					tmp = t[0][1];
					t[0][1] = t[1][2];
					t[1][2] = t[2][1];
					t[2][1] = t[1][0];
					t[1][0] = tmp;
				}
			}
		}
	}
	return 0;
}
