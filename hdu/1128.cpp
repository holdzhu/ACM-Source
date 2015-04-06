#include <cstdio>
#include <cstring>

bool a[1000100];

int main()
{
	memset(a, 0, sizeof(a));
	for (int i = 1; i <= 1000000; ++i)
	{
		int t = i, s = 0;
		while (t > 0)
		{
			s += t % 10;
			t /= 10;
		}
		a[i + s] = true;
	}
	for (int i = 1; i <= 1000000; ++i)
	{
		if (!a[i])
		{
			printf("%d\n", i);
		}
	}
	return 0;
}
