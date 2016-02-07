#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

const int mod   = 1e9 + 7;
const double PI = acos(-1);

struct Virt
{
	double r, i;

	Virt(double r = 0.0, double i = 0.0)
	{
		this->r = r;
		this->i = i;
	}

	Virt operator+(const Virt &x)
	{
		return Virt(r + x.r, i + x.i);
	}

	Virt operator-(const Virt &x)
	{
		return Virt(r - x.r, i - x.i);
	}

	Virt operator*(const Virt &x)
	{
		return Virt(r * x.r - i * x.i, i * x.r + r * x.i);
	}
};

void Rader(Virt F[], int len)
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

void FFT(Virt F[], int len, int on)
{
	Rader(F, len);
	for (int h = 2; h <= len; h <<= 1)
	{
		Virt wn(cos(-on * 2 * PI / h), sin(-on * 2 * PI / h));
		for (int j = 0; j < len; j += h)
		{
			Virt w(1, 0);
			for (int k = j; k < j + h / 2; k++)
			{
				Virt u	   = F[k];
				Virt t	   = w * F[k + h / 2];
				F[k]		 = u + t;
				F[k + h / 2] = u - t;
				w			= w * wn;
			}
		}
	}
	if (on == -1)
		for (int i = 0; i < len; i++)
			F[i].r /= len;
}

void Conv(Virt a[], Virt b[], int len)
{
	FFT(a, len, 1);
	FFT(b, len, 1);
	for (int i = 0; i < len; i++)
		a[i] = a[i] * b[i];
	FFT(a, len, -1);
}

int len;
int k;

void mul(long long *s, long long a)
{
	long long t = 1;
	for (int i = 0; i <= k; ++i)
	{
		s[i] = s[i] * t % mod;
		t	= t * a % mod;
	}
}

Virt A[3][2 << 16], B[3][2 << 16], _A[2 << 16], _B[2 << 16];
long long c[30001];
const int smod1	= 4e4;
const int smod2	= 1e3 + 10;
const int base1[3] = {1, smod1, smod1 *smod1};
const int base2[3] = {1, smod2, smod2 *smod2};
void calc(long long *a, long long *b)
{
	for (int i = 1; i <= k; ++i)
		c[i] = 0;
	for (int i = 0; i < 2; ++i)
	{
		for (int j = 0; j < len; ++j)
			A[i][j].r = A[i][j].i = 0;
		for (int j = 1; j <= k; ++j)
		{
			A[i][j].r = a[j] % smod1;
			a[j] /= smod1;
		}
	}
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < len; ++j)
			B[i][j].r = B[i][j].i = 0;
		for (int j = 1; j <= k; ++j)
		{
			B[i][j].r = b[j] % smod2;
			b[j] /= smod2;
		}
	}
	for (int i = 0; i < 2; ++i)
		for (int j = 0; j < 3; ++j)
		{
			for (int l = 0; l < len; ++l)
				_A[l] = A[i][l], _B[l] = B[j][l];
			Conv(_A, _B, len);
			for (int l = 1; l <= k; ++l)
				c[l] = (c[l]
						+ (long long)(_A[l].r + 0.5) % mod * base1[i] % mod
							  * base2[j] % mod)
					   % mod;
		}
	for (int i = 1; i <= k; ++i)
		a[i] = c[i];
}

long long inv[30001];
long long fac[30001];
long long facinv[30001];
long long ret[30001];
long long tmp[30001];

long long solve(int n)
{
	if (n == 1)
	{
		for (int i = 1; i <= k; ++i)
			ret[i] = facinv[i];
		return 2;
	}
	else if (n & 1)
	{
		long long pw = solve(n - 1);
		mul(ret, 2);
		for (int i = 1; i <= k; ++i)
			tmp[i] = facinv[i];
		calc(ret, tmp);
		return pw * 2 % mod;
	}
	else
	{
		long long pw = solve(n / 2);
		copy(ret, ret + k + 1, tmp);
		mul(tmp, pw);
		calc(ret, tmp);
		return pw * pw % mod;
	}
}

int main()
{
	long long n;
	scanf("%I64d %d", &n, &k);
	if (n > k)
		puts("0");
	else
	{
		inv[1] = fac[0] = fac[1] = facinv[0] = facinv[1] = 1;
		for (int i = 2; i <= k; ++i)
		{
			inv[i]	= inv[mod % i] * (mod - mod / i) % mod;
			fac[i]	= fac[i - 1] * i % mod;
			facinv[i] = facinv[i - 1] * inv[i] % mod;
		}
		for (len = 1; len <= k * 2; len <<= 1)
			;
		solve(n);
		long long ans = 0;
		for (int i = 1; i <= k; ++i)
			ans = (ans + ret[i] * facinv[k - i] % mod * fac[k] % mod) % mod;
		printf("%I64d\n", ans);
	}
	return 0;
}
