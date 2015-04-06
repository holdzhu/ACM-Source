#include <cstdio>

int main()
{
	int T;
	int H, M;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d:%d", &H, &M);
		if (M % 2)
		{
			int a;
			a = M * 11 - (H % 12) * 60;
			if (a < 0)
			{
				a = -a;
			}
			if (a > 360)
			{
				a = 720 - a;
			}
			printf("%d/2\n", a);
		}
		else
		{
			int t = M / 2 * 11 - 30 * (H % 12);
			if (t < 0)
			{
				t = -t;
			}
			if (t > 180)
			{
				t = 360 - t;
			}
			printf("%d\n", t);
		}
	}
	return 0;
}
