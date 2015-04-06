#include <cstdio>
#include <cstring>

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int n;
		scanf("%d", &n);
		char m[n][n + 1];
		for (int i = 0; i < n; ++i)
		{
			scanf("%s", m[i]);
		}
		bool hasC[n];
		bool hasR[n];
		memset(hasC, 0, sizeof(hasC));
		memset(hasR, 0, sizeof(hasR));
		int CA[n][27];
		int RA[n][27];
		memset(CA, 0, sizeof(CA));
		memset(RA, 0, sizeof(RA));
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				if (m[i][j] == '0')
				{
					CA[j][0]++;
					RA[i][0]++;
				}
				else
				{
					CA[j][m[i][j] - 'A' + 1]++;
					RA[i][m[i][j] - 'A' + 1]++;
				}
			}
		}
		for (int t = 0; t < n * 2; ++t)
		{
			bool have = false;
			for (int C = 0; C < n && !have; ++C)
			{
				if (!hasC[C])
				{
					char flag = 0;
					for (int i = 1; i <= 26; ++i)
					{
						if (CA[C][i] + CA[C][0] == n)
						{
							flag = i;
							break;
						}
					}
					if (flag)
					{
						if (CA[C][0] == n)
						{
							printf("C %d A\n", C + 1);
						}
						else
						{
							for (int i = 0; i < n; ++i)
							{
								if (m[i][C] != '0')
								{
									RA[i][m[i][C] - 'A' + 1]--;
									RA[i][0]++;
									m[i][C] = '0';
								}
							}
							printf("C %d %c\n", C + 1 ,flag - 1 + 'A');
						}
						hasC[C] = true;
						have = true;
					}
				}
			}
			for (int R = 0; R < n && !have; ++R)
			{
				if (!hasR[R])
				{
					char flag = 0;
					for (int i = 1; i <= 26; ++i)
					{
						if (RA[R][i] + RA[R][0] == n)
						{
							flag = i;
							break;
						}
					}
					if (flag)
					{
						if (RA[R][0] == n)
						{
							printf("R %d A\n", R + 1);
						}
						else
						{
							for (int i = 0; i < n; ++i)
							{
								if (m[R][i] != '0')
								{
									CA[i][m[R][i] - 'A' + 1]--;
									CA[i][0]++;
									m[R][i] = '0';
								}
							}
							printf("R %d %c\n", R + 1 ,flag - 1 + 'A');
						}
						hasR[R] = true;
						have = true;
					}
				}
			}
		}
		printf("\n");
	}
	return 0;
}
