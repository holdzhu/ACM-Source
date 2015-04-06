#include <cstdio>
#include <cstring>
#include <map>

using namespace std;

char s[2][81];

int main()
{
	int T;
	scanf("%d", &T);
	getchar();
	while (T--)
	{
		gets(s[0]);
		gets(s[1]);
		map<char, int> m;
		bool yes = true;
		for (int times = 0; times < 10; ++times)
		{
			m.clear();
			int ans[2];
			for (int i = 0; i < 2; ++i)
			{
				int l = strlen(s[i]);
				long long num[81];
				int cnum = 0;
				char type[81];
				int ctype = 0;
				for (int j = 0; j < l; ++j)
				{
					if ((s[i][j] >= '0' && s[i][j] <= '9') || (s[i][j] >= 'a' && s[i][j] <= 'z') || (s[i][j] >= 'A' && s[i][j] <= 'Z'))
					{
						int t;
						if (s[i][j] >= '0' && s[i][j] <= '9')
						{
							t = s[i][j] - '0';
						}
						else
						{
							if (!m.count(s[i][j]))
							{
								m[s[i][j]] = (s[i][j] + times) % 13;
							}
							t = m[s[i][j]];
						}
						if (ctype && type[ctype - 1] == '*')
						{
							num[cnum - 1] *= t;
							ctype--;
						}
						else
						{
							num[cnum++] = t;
						}
					}
					else if (s[i][j] == '+' || s[i][j] == '-')
					{
						if (ctype && type[ctype - 1] == '+')
						{
							num[cnum - 2] += num[cnum - 1];
							cnum--;
							type[ctype - 1] = s[i][j];
						}
						else if (ctype && type[ctype - 1] == '-')
						{
							num[cnum - 2] -= num[cnum - 1];
							cnum--;
							type[ctype - 1] = s[i][j];
						}
						else
						{
							type[ctype++] = s[i][j];
						}
					}
					else if (s[i][j] == '*' || s[i][j] == '(')
					{
						type[ctype++] = s[i][j];
					}
					else if (s[i][j] == ')')
					{
						while (type[ctype - 1] != '(')
						{
							if (type[ctype - 1] == '+')
							{
								num[cnum - 2] += num[cnum - 1];
								cnum--;
								ctype--;
							}
							else if (type[ctype - 1] == '-')
							{
								num[cnum - 2] -= num[cnum - 1];
								cnum--;
								ctype--;
							}
							else
							{
								num[cnum - 2] *= num[cnum - 1];
								cnum--;
								ctype--;
							}
						}
						ctype--;
					}
				}
				while (ctype)
				{
					if (type[ctype - 1] == '+')
					{
						num[cnum - 2] += num[cnum - 1];
						cnum--;
						ctype--;
					}
					else if (type[ctype - 1] == '-')
					{
						num[cnum - 2] -= num[cnum - 1];
						cnum--;
						ctype--;
					}
					else
					{
						num[cnum - 2] *= num[cnum - 1];
						cnum--;
						ctype--;
					}
				}
				ans[i] = num[0];
			}
			if (ans[0] != ans[1])
			{
				yes = false;
				break;
			}
		}
		if (yes)
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
		
	}
	return 0;
}
