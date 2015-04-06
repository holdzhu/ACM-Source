#include <cstdio>
#include <cstring>

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		char A[5], B[5];
		scanf("%s %s", A, B);
		int la = strlen(A);
		int lb = strlen(B);
		int ma = 0;
		int mb = 0;
		for (int i = 0; i < la; ++i)
		{
			if (A[i] - '0' > ma)
			{
				ma = A[i] - '0';
			}
		}
		for (int i = 0; i < lb; ++i)
		{
			if (B[i] - '0' > mb)
			{
				mb = B[i] - '0';
			}
		}
		int m = (ma > mb) ? ma : mb;
		m++;
		int a = 0, b = 0;
		for (int i = 0; i < la; ++i)
		{
			a *= m;
			a += A[i] - '0';
		}
		for (int i = 0; i < lb; ++i)
		{
			b *= m;
			b += B[i] - '0';
		}
		a += b;
		int c = 0;
		while (a)
		{
			a /= m;
			c++;
		}
		printf("%d\n", c);
	}
	return 0;
}
