#include <cstdio>

const char s[] = "110110001110110001000000000110110001110110001000000000001001000001001000110110001";

int main()
{
	int cnt = 0;
	for (int a = 0; a < 3; ++a)
	{
		for (int b = 0; b < 3; ++b)
		{
			for (int c = 0; c < 3; ++c)
			{
				for (int d = 0; d < 3; ++d)
				{
					if (a && b && c && d && s[a * 27 + b * 9 + c * 3 + d] == '1')
					{
						cnt++;
					}
				}
			}
		}
	}
	printf("%d\n", cnt);
	return 0;
}
