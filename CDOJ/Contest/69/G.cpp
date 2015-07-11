#include <cstdio>
#include <cstring>

int n, m, d, k;

struct Matrix
{
	long long a[500];
	Matrix()
	{
		memset(a, 0, sizeof a);
		a[0] = 1;
	}
};

Matrix operator * (const Matrix& A, const Matrix& B)
{
	Matrix* S = new Matrix;
	for (int j = 0; j < n; ++j)
	{
		S->a[j] = 0;
		for (int k = 0; k < n; ++k)
		{
			S->a[j] += A.a[k] * B.a[(k - j + n) % n];
			S->a[j] %= m;
		}
	}
	return *S;
}

Matrix* powmod(Matrix* S, int k)
{
	Matrix* R = new Matrix();
	while (k)
	{
		if (k & 1)
		{
			*R = *R * *S;
		}
		*S = *S * *S;
		k >>= 1;
	}
	return R;
}

int a[500];

int main()
{
	scanf("%d %d %d %d", &n, &m, &d, &k);
	Matrix* S = new Matrix();
	for (int j = 0; j < d; ++j)
	{
		S->a[(j + 1) % n] = 1;
		S->a[(-j - 1 + n) % n] = 1;
	}
	Matrix* R = powmod(S, k);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < n; ++i)
	{
		if (i)
		{
			printf(" ");
		}
		long long s = 0;
		for (int j = 0; j < n; ++j)
		{
			s += R->a[(j - i + n) % n] * a[j];
			s %= m;
		}
		printf("%lld", s);
	}
	printf("\n");
	return 0;
}
