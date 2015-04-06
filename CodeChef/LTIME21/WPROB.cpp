#include <cstdio>

char s[100001];
const char sc[6][4] = {"rgb", "rbg", "grb", "gbr", "brg", "bgr"};

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%s", s);
		long long min = 100000000000000;
		for (int i = 0; i < 6; ++i)
		{
			int c[3] = {0, 0, 0};
			long long ans = 0;
			for (int j = 0; s[j] != '\0'; ++j)
			{
				if (s[j] == sc[i][0])
				{
					ans += c[1] + c[2];
					c[0]++;
				}
				else if (s[j] == sc[i][1])
				{
					ans += c[2];
					c[1]++;
				}
				else
				{
					c[2]++;
				}
			}
			if (ans < min)
			{
				min = ans;
			}
		}
		printf("%lld\n", min);
	}
	return 0;
}
