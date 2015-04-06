#include <cstdio>

int main()
{
	int n;
	long long m;
	scanf("%d %I64d", &n, &m);
	m--;
	bool a[n - 1];
	for (int i = 0; i < n - 1; ++i)
	{
		a[i] = m % 2;
		m >>= 1;
	}
	int s[n];
	int L = 0;
	int R = n - 1;
	for (int i = n - 2; i >= 0; --i)
	{
		if (a[i])
		{
			s[R--] = n - 1 - i;
		}
		else
		{
			s[L++] = n - 1 - i;
		}
	}
	s[L] = n;
	for (int i = 0; i < n; ++i)
	{
		printf("%d ", s[i]);
	}
	printf("\n");
	return 0;
}
