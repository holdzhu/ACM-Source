#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

const int mod		= 1e9 + 7;
const long double PI = acosl(-1);

struct Virt
{
	long double r, i;

	Virt(long double r = 0.0, long double i = 0.0)
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
		Virt wn(cosl(-on * 2 * PI / h), sinl(-on * 2 * PI / h));
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

long long B[1000002];
long long fac[1000002];
long long inv[1000002];
long long facinv[1000002];

const int smod   = 3e5;
const int base[] = {1, smod};
Virt a[1 << 21], b[1 << 21];

void CDQ(int L, int R)
{
	if (L == R)
	{
		if (B[L])
			B[L] = mod - B[L];
		return;
	}
	int M = (L + R) >> 1;
	CDQ(L, M);
	int len = 1;
	for (; len <= (R + 1 - L) * 2; len <<= 1)
		;
	for (int i = 0; i < 2; ++i)
		for (int j = 0; j < 2; ++j)
		{
			for (int k = 0; k < len; ++k)
				a[k].r = a[k].i = b[k].r = b[k].i = 0;
			for (int k = L; k <= M; ++k)
				a[k - L].r = i ? B[k] / smod : B[k] % smod;
			for (int k = 0; k <= R - L; ++k)
				b[k].r = j ? facinv[k + 1] / smod : facinv[k + 1] % smod;
			Conv(a, b, len);
			for (int k = M + 1; k <= R; ++k)
				B[k] = (B[k]
						+ (long long)(fmodl(a[k - L].r, mod) + 0.5) * base[i]
							  % mod * base[j] % mod)
					   % mod;
		}
	CDQ(M + 1, R);
}

long long pw[1000002];

int main()
{
	freopen("table", "w", stdout);
	int n, k;
	scanf("%d %d", &n, &k);
	if (k == 0)
	{
		printf("%d\n", n);
		return 0;
	}
	B[0]   = mod - 1;
	fac[0] = fac[1] = inv[0] = inv[1] = facinv[0] = facinv[1] = pw[0] = 1;
	pw[1] = n + 1;
	for (int i = 2; i <= k + 1; ++i)
	{
		fac[i]	= fac[i - 1] * i % mod;
		inv[i]	= inv[mod % i] * (mod - mod / i) % mod;
		facinv[i] = facinv[i - 1] * inv[i] % mod;
		pw[i]	 = pw[i - 1] * (n + 1) % mod;
	}
	CDQ(0, k);
	for (int i = 0; i <= k; ++i)
		printf("%d,", B[i]);
	// long long ans = 0;
	// for (int i = 0; i <= k; ++i)
	// 	ans = (ans
	// 		   + fac[k + 1] * facinv[k + 1 - i] % mod * B[i] % mod
	// 				 * pw[k + 1 - i] % mod)
	// 		  % mod;
	// printf("%I64d\n", ans * inv[k + 1] % mod);
	return 0;
}
