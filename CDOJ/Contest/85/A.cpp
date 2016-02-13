#include <cstdio>

int main()
{
	int N;
	scanf("%d", &N);
	long long a = 1, b = 2;
	bool flag = true;
	for (int i = 0; i < N; ++i)
	{
		int t;
		scanf("%d", &t);
		if (t < a)
		{
			flag = false;
			break;
		}
		long long c = a + b;
		a = b;
		b = c;
	}
	puts(N == 2 || flag ? "Find it" : "Please forgive me");
	return 0;
}
