#include <cstdio>
#include <complex>
#include <algorithm>

using namespace std;

const long double pi = acos(-1);
int s[100001];
complex<long double> x1[131072];
complex<long double> x2[131072];

void change(complex<long double> x[], int len)
{
	for (int i = 1, j = len / 2; i < len - 1; ++i)
	{
		if (i < j)
		{
			swap(x[i], x[j]);
		}
		int k = len / 2;
		while (j >= k)
		{
			j -= k;
			k /= 2;
		}
		if (j < k)
		{
			j += k;
		}
	}
}

void fft(complex<long double> x[], int len, int on)
{
	change(x, len);
	for (int i = 2; i <= len; i <<= 1)
	{
		complex<long double> wn(cos(-on * 2 * pi / i), sin(-on * 2 * pi / i));
		for (int j = 0; j < len; j += i)
		{
			complex<long double> w(1, 0);
			for (int k = j; k < j + i / 2; ++k)
			{
				complex<long double> u = x[k];
				complex<long double> t = w * x[k + i / 2];
				x[k] = u + t;
				x[k + i / 2] = u - t;
				w = w * wn;
			}
		}
	}
	if (on == -1)
	{
		for (int i = 0; i < len; ++i)
		{
			x[i] /= len;
		}
	}
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int n;
		scanf("%d", &n);
		s[0] = 0;
		long long zeros = 0;
		long long ans0 = 0;
		for (int i = 1; i <= n; ++i)
		{
			scanf("%d", &s[i]);
			if (s[i] == 0)
			{
				zeros++;
			}
			else
			{
				zeros = 0;
			}
			ans0 += zeros * (zeros + 1) / 2;
			s[i] += s[i - 1];
		}
		int len = 1;
		while (len <= s[n] * 2)
		{
			len <<= 1;
		}
		for (int i = 0; i < len; ++i)
		{
			x1[i] = complex<long double>(0);
			x2[i] = complex<long double>(0);
		}
		for (int i = 0; i <= n; ++i)
		{
			x1[s[i]] += complex<long double>(i);
			x2[s[n] - s[i]] += complex<long double>(1);
		}
		fft(x1, len, 1);
		fft(x2, len, 1);
		for (int i = 0; i < len; ++i)
		{
			x1[i] *= x2[i];
		}
		fft(x1, len, -1);
		printf("%lld\n", ans0);
		for (int i = 1; i <= s[n]; ++i)
		{
			printf("%lld\n", (long long)((x1[s[n] + i] - x1[s[n] - i]).real() + 0.5));
		}
	}
	return 0;
}
