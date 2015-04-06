#include <cstdio>
#include <cstdlib>

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		char s[33];
		scanf("%s", s);
		int d = 0;
		for (int i = 0; i < 32; ++i)
		{
			d *= 2;
			d += s[i] - '0';
		}
		printf("%d %X\n", d, d);
	}
	return 0;
}
