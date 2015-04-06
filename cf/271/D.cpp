#include <cstdio>

int C(int a, int b)
{
	unsigned long long l = 1;
	if (b * 2 > a)
	{
		b = a - b;
	}
	for (int i = a; i > a - b; --i)
	{
		l *= i;
	}
	for (int i = 1; i <= b; ++i)
	{
		l /= i;
	}
	return l % 1000000007;
}

int main()
{
	int t, k;
	scanf("%d %d", &t, &k);
	int s[100000];
	for (int i = 0; i < k - 1; ++i)
	{
		s[i] = 1;
	}
	for (int i = k - 1; i < 100000; ++i)
	{
		s[i] = s[i - 1] + s[i - k];
	}
	while (t--)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		int _s = 0;
		for (int i = a - 1; i < b; ++i)
		{
			_s += s[i];
			_s = _s % 1000000007;
		}
		printf("%d\n", _s);
	}
}