#include <cstdio>

long long pow10(long long t, long long mod)
{
	if (t == 0)
	{
		return 1 % mod;
	}
	long long s = pow10(t / 2, mod);
	s *= s;
	s %= mod;
	if (t % 2)
	{
		s *= 10;
		s %= mod;
	}
	return s;
}

int main()
{
	long long k, mod;
	FILE *fin, *fout;
	fin = fopen("zeroes.in", "rb");
	fout = fopen("zeroes.out", "wb");
	fscanf(fin, "%lld %lld", &k, &mod);
	scanf("%lld %lld", &k, &mod);
	long long ans = (k - 1) % mod * (pow10((k - 1), mod) + 1) % mod - (pow10((k - 1), mod * 9) - 10) / 9;
	ans %= mod;
	while (ans < 0)
	{
		ans += mod;
	}
	printf("%lld\n", ans % mod);
	fprintf(fout, "%lld\n", ans % mod);
	fclose(fin);
	fclose(fout);
	return 0;
}
