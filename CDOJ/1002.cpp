#include <cstdio>
#include <cstring>

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		char s[125];
		int num1 = -1;
		int num2 = -1;
		char type1 = 0;
		char type2 = 0;
		scanf("%s", s);
		int l = strlen(s);
		int t = 0;
		for (int i = 0; i <= l; ++i)
		{
			if (s[i] >= '0' && s[i] <= '9')
			{
				t *= 10;
				t += s[i] - '0';
			}
			else if (s[i] == '+' || s[i] == '-' || s[i] == '\0')
			{
				if (type2)
				{
					if (type2 == '*')
					{
						num2 *= t;
					}
					else
					{
						num2 /= t;
					}
					if (type1 == '+')
					{
						num1 += num2;
					}
					else
					{
						num1 -= num2;
					}
					type2 = 0;
				}
				else if (type1)
				{
					if (type1 == '+')
					{
						num1 += t;
					}
					else if (type1 == '-')
					{
						num1 -= t;
					}
					else if (type1 == '*')
					{
						num1 *= t;
					}
					else
					{
						num1 /= t;
					}
				}
				else
				{
					num1 = t;
				}
				t = 0;
				type1 = s[i];
			}
			else
			{
				if (type2)
				{
					if (type2 == '*')
					{
						num2 *= t;
					}
					else
					{
						num2 /= t;
					}
					type2 = s[i];
				}
				else if (type1)
				{
					if (type1 == '+' || type1 == '-')
					{
						num2 = t;
						type2 = s[i];
					}
					else
					{
						if (type1 == '*')
						{
							num1 *= t;
						}
						else
						{
							num1 /= t;
						}
						type1 = s[i];
					}
				}
				else
				{
					num1 = t;
					type1 = s[i];
				}
				t = 0;
			}
		}
		printf("%d\n", num1);
	}
	return 0;
}
