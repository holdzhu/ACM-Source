#include <cstdio>

int f[1000000];

int main()
{
	f[0] = 0;
	for (int i = 1; i < 1000000; ++i)
	{
		int t = i;
		int num[6];
		int p = 0;
		bool flag = true;
		while (t)
		{
			num[p] = t % 10;
			t /= 10;
			if (num[p] == 4 || (p > 0 && num[p] == 6 && num[p - 1] == 2))
			{
				flag = false;
				break;
			}
			p++;
		}
		f[i] = f[i - 1] + flag;
	}
	int l, r;
	while (scanf("%d %d", &l, &r) == 2 && l && r)
	{
		printf("%d\n", f[r] - f[l - 1]);
	}
	return 0;
}
