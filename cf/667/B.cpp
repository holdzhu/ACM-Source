#include <cstdio>

int main()
{
	long long sum = 0;
	int n, mx = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		int l;
		scanf("%d", &l);
		if (l > mx)
			mx = l;
		sum += l;
	}
	printf("%I64d\n", mx + mx - sum + 1);
	return 0;
}
