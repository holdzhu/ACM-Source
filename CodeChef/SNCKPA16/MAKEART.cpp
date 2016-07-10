#include <cstdio>

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int N;
		scanf("%d", &N);
		bool flag = false;
		int a = -1;
		int b = -1;
		for (int i = 0; i < N; ++i)
		{
			int c;
			scanf("%d", &c);
			if (a == b && a == c)
				flag = true;
			a = b;
			b = c;
		}
		puts(flag ? "Yes" : "No");
	}
	return 0;
}
