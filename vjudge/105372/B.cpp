#include <cstdio>

const int w[6] = {2, 4, 3, 4, 3, 4};

bool read()
{
	char c;
	scanf(" (%c", &c);
	if (c == '*')
	{
		scanf(")");
	}
	return c == '*';
}

int d[6];

int main()
{
	int T;
	scanf("%d", &T);
	for (int kase = 1; kase <= T; ++kase)
	{
		for (int i = 0; i < 6; ++i)
		{
			d[i] = 0;
			for (int j = 0; j < w[i]; ++j)
			{
				d[i] <<= 1;
				d[i] += read();
			}
		}
		printf("Case %d: %d%d:%d%d:%d%d\n", kase, d[0], d[1], d[2], d[3], d[4], d[5]);
	}
	return 0;
}
