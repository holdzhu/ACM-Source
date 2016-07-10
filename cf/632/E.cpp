#include <cstdio>
#include <cmath>
#include <complex>
#include <algorithm>

using namespace std;

const double PI = acos(-1);

void Rader(complex<double> F[], int len)
{
	int j = len >> 1;
	for (int i = 1; i < len - 1; i++)
	{
		if (i < j)
			swap(F[i], F[j]);
		int k = len >> 1;
		while (j >= k)
		{
			j -= k;
			k >>= 1;
		}
		if (j < k)
			j += k;
	}
}

void FFT(complex<double> F[], int len, int on)
{
	Rader(F, len);
	for (int h = 2; h <= len; h <<= 1)
	{
		complex<double> wn(cos(-on * 2 * PI / h), sin(-on * 2 * PI / h));
		for (int j = 0; j < len; j += h)
		{
			complex<double> w(1, 0);
			for (int k = j; k < j + h / 2; k++)
			{
				complex<double> u = F[k];
				complex<double> t = w * F[k + h / 2];
				F[k] = u + t;
				F[k + h / 2] = u - t;
				w = w * wn;
			}
		}
	}
}

void Conv(complex<double> a[], complex<double> b[], int len)
{
	FFT(a, len, 1);
	FFT(b, len, 1);
	for (int i = 0; i < len; i++)
		a[i] = a[i] * b[i];
	FFT(a, len, -1);
}

complex<double> A[1 << 20], B[1 << 20];

void solve(bool *a, bool *b, int n)
{
	int len = 1;
	while (len <= n + 1)
		len <<= 1;
	for (int i = 0; i < len; ++i)
	{
		A[i] = a[i];
		B[i] = b[i];
	}
	Conv(A, B, len);
	for (int i = 0; i <= n; ++i)
		a[i] = A[i].real() * 2 > len;
}

int mx = 0;
bool dp[1 << 20];
bool b[1 << 20];

void solve(int n)
{
	if (n == 0)
	{
		dp[0] = true;
	}
	else if (n & 1)
	{
		solve(n - 1);
		solve(dp, b, n * mx);
	}
	else
	{
		solve(n >> 1);
		solve(dp, dp, n * mx);
	}
}

int main()
{
	int n, k;
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; ++i)
	{
		int a;
		scanf("%d", &a);
		b[a] = true;
		mx = max(mx, a);
	}
	solve(k);
	for (int i = 1; i <= mx * k; ++i)
		if (dp[i])
			printf("%d ", i);
	return 0;
}
