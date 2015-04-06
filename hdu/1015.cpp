#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	char s[13];
	while (scanf("%d %s", &n, s) == 2 && n)
	{
		int l = strlen(s);
		sort(s, s + l);
		for (int i = 0; i < l; ++i)
		{
			s[i] -= 'A' - 1;
		}
		bool flag = true;
		for (int c1 = l - 1; c1 >= 0 && flag; --c1)
		{
			for (int c2 = l - 1; c2 >= 0 && flag; --c2)
			{
				if (c1 != c2)
				{
					for (int c3 = l - 1; c3 >= 0 && flag; --c3)
					{
						if (c1 != c3 && c2 != c3)
						{
							for (int c4 = l - 1; c4 >= 0 && flag; --c4)
							{
								if (c1 != c4 && c2 != c4 && c3 != c4)
								{
									for (int c5 = l - 1; c5 >= 0 && flag; --c5)
									{
										if (c1 != c5 && c2 != c5 && c3 != c5 && c4 != c5)
										{
											if (n == s[c1] - s[c2] * s[c2] + s[c3] * s[c3] * s[c3] - s[c4] * s[c4] * s[c4] * s[c4] + s[c5] * s[c5] * s[c5] * s[c5] * s[c5])
											{
												flag = false;
												printf("%c%c%c%c%c\n", s[c1] + 'A' - 1, s[c2] + 'A' - 1, s[c3] + 'A' - 1, s[c4] + 'A' - 1, s[c5] + 'A' - 1);
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
		if (flag)
		{
			printf("no solution\n");
		}
	}
	return 0;
}
