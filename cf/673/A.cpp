#include <cstdio>

int main()
{
	int n;
	scanf("%d", &n);
	int last = 15;
	for (int i = 0; i < n; ++i)
	{
		int t;
		scanf("%d", &t);
		if (t <= last)
			last = t + 15;
		else
			break;
	}
	if (last > 90)
		last = 90;
	printf("%d\n", last);
	return 0;
}
