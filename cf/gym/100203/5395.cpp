#include <cstdio>
#include <cstring>
#include <cmath>

const int maxn = 64;

struct Matrix
{
	double a[maxn][maxn];
	Matrix()
	{
		memset(a, 0, sizeof a);
	}
};

Matrix add(const Matrix& A, const Matrix& B, int n = maxn, int t1 = 0, int l1 = 0, int t2 = 0, int l2 = 0)
{
	printf("add %d %d %d %d %d\n", n, t1, l1, t2, l2);
	Matrix S;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			S.a[i][j] = A.a[t1 + i][l1 + j] + B.a[t2 + i][l2 + j];
		}
	}
	printf("end\n");
	return S;
}

Matrix sub(const Matrix& A, const Matrix& B, int n = maxn, int t1 = 0, int l1 = 0, int t2 = 0, int l2 = 0)
{
	printf("sub %d %d %d %d %d\n", n, t1, l1, t2, l2);
	Matrix S;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			S.a[i][j] = A.a[t1 + i][l1 + j] - B.a[t2 + i][l2 + j];
		}
	}
	printf("end\n");
	return S;
}

Matrix strassen(const Matrix& A, const Matrix& B, int n = maxn, int t1 = 0, int l1 = 0, int t2 = 0, int l2 = 0)
{
	printf("str %d %d %d %d %d\n", n, t1, l1, t2, l2);
	Matrix C;
	if (n == 1)
	{
		C.a[0][0] = A.a[t1][l1] * B.a[t2][l2];
	}
	else
	{
		int n2 = n / 2;
		Matrix S1 = sub(B, B, n2, t1, l1 + n2, t2 + n2, l2 + n2);
		Matrix S2 = add(A, A, n2, t1, l1, t2, l2 + n2);
		Matrix S3 = add(A, A, n2, t1 + n2, l1, t2 + n2, l2 + n2);
		Matrix S4 = sub(B, B, n2, t1 + n2, l1, t2, l2);
		Matrix S5 = add(A, A, n2, t1, l1, t2 + n2, l2 + n2);
		Matrix S6 = add(B, B, n2, t1, l1, t2 + n2, l2 + n2);
		Matrix S7 = sub(A, A, n2, t1, l1 + n2, t2 + n2, l2 + n2);
		Matrix S8 = add(B, B, n2, t1 + n2, l1, t2 + n2, l2 + n2);
		Matrix S9 = sub(A, A, n2, t1, l1, t2 + n2, l2);
		Matrix S0 = add(B, B, n2, t1, l1, t2, l2 + n2);
		Matrix P1 = strassen(A, S1, n2, t1, l1, 0, 0);
		Matrix P2 = strassen(S2, B, n2, 0, 0, t2 + n2, l2 + n2);
		Matrix P3 = strassen(S3, B, n2, 0, 0, t2, l2);
		Matrix P4 = strassen(A, S4, n2, t1 + n2, l1 + n2, 0, 0);
		Matrix P5 = strassen(S5, S6, n2);
		Matrix P6 = strassen(S7, S8, n2);
		Matrix P7 = strassen(S9, S0, n2);
		Matrix C11 = add(sub(add(P5, P4, n2), P2, n2), P6, n2);
		Matrix C12 = add(P1, P2, n2);
		Matrix C21 = add(P3, P4, n2);
		Matrix C22 = sub(sub(add(P5, P1, n2), P3, n2), P7, n2);
		for (int i = 0; i < n2; ++i)
		{
			for (int j = 0; j < n2; ++j)
			{
				C.a[i][j] = C11.a[i][j];
				C.a[i + n2][j] = C21.a[i][j];
				C.a[i][j + n2] = C12.a[i][j];
				C.a[i + n2][j + n2] = C22.a[i][j];
			}
		}
	}
	printf("end\n");
	return C;
}

Matrix A;
Matrix S;

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int m, n;
		double X;
		scanf("%d %d %lf", &m, &n, &X);
		double Cos = cos(X);
		double Sin = sin(X);
		for (int i = 0; i < m * 2; ++i)
		{
			for (int j = 0; j < m * 2; ++j)
			{
				S.a[i][j] = i == j;
			}
		}
		for (int i = 0; i < m; ++i)
		{
			A.a[i][i] = Cos;
			A.a[m + i][i] = Sin;
			A.a[i][m + i] = -Sin;
			A.a[m + i][m + i] = Cos;
			if (i)
			{
				A.a[i][i - 1] = Cos;
				A.a[m + i][i - 1] = Sin;
			}
		}
		n--;
		while (n)
		{
			if (n & 1)
			{
				S = strassen(S, A);
			}
			A = strassen(A, A);
			n >>= 1;
		}
		printf("%.1f\n", S.a[m - 1][0] * Cos + S.a[m - 1][m] * Sin);
	}
	return 0;
}
