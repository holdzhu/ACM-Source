#include <cstdio>

int main()
{
	int T;
	scanf("%d", &T);
	bool p[65536];
	for (int i = 2; i < 65536; ++i)
	{
		if (i % 2)
		{
			p[i] = false;
		}
		else
		{
			p[i] = true;
		}
	}
	p[0] = false;
	p[1] = true;
	for (int i = 3; i < 256; i += 2)
	{
		for (int j = i * i; j <= 65536; j += i)
		{
			p[j - 1] = false;
		}
	}
	while (T--)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		for (int i = a; i <= b; ++i)
		{
			if (p[i - 1])
			{
				printf("%d ", i);
			}
		}
		printf("\n");
	}
	return 0;
}
