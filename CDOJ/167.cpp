#include <cstdio>

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		int m[40];
		int n[40];
		int pos;
		for (pos = 0; b; ++pos)
		{
			m[pos] = b % 2;
			b /= 2;
		}
		n[0] = a % 10000;
		int s = (m[0]) ? n[0] : 1;
		for (int i = 1; i < pos; ++i)
		{
			n[i] = (n[i - 1] * n[i - 1]) % 10000;
			if (m[i])
			{
				s *= n[i];
				s %= 10000;
			}
		}
		printf("%04d\n", s);
	}
	return 0;
}
