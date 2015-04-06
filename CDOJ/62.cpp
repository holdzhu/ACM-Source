#include <cstdio>

int main()
{
	int L, M;
	scanf("%d %d", &L, &M);
	bool t[L + 1];
	for (int i = 0; i < L + 1; ++i)
	{
		t[i] = true;
	}
	while (M--)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		for (int i = a; i <= b; ++i)
		{
			t[i] = false;
		}
	}
	int s = 0;
	for (int i = 0; i < L + 1; ++i)
	{
		if (t[i])
		{
			s++;
		}
	}
	printf("%d\n", s);
	return 0;
}
