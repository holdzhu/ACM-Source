#include <cstdio>

int main()
{
	for (int i = 1000; i < 10000; ++i)
	{
		int s1 = i % 10 + i / 10 % 10 + i / 100 % 10 + i / 1000;
		int s2 = i % 12 + i / 12 % 12 + i / 144 % 12 + i / 1728;
		int s3 = i % 16 + i / 16 % 16 + i / 256 % 16 + i / 4096;
		if (s1 == s2 && s2 == s3)
		{
			printf("%d\n", i);
		}
	}
	return 0;
}
