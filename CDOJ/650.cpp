#include <cstdio>

int main()
{
	int T;
	scanf("%d", &T);
	int days[11] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30};
	while (T--)
	{
		int y, m, d;
		scanf("%d %d %d", &y, &m, &d);
		if (y % 4 || (y % 100 == 0 && y / 100 % 4))
		{
			days[1] = 28;
		}
		else
		{
			days[1] = 29;
		}
		int s = 0;
		for (int i = 0; i < m - 1; ++i)
		{
			s += days[i];
		}
		s += d;
		printf("%d\n", s);
	}
	return 0;
}
