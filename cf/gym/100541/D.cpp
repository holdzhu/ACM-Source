#include <cstdio>
#include <cstring>

int main()
{
	int startt[100];
	int startl[100];
	int rel[100];
	int endt[100];
	int endd[100];
	for (int i = 0; i < 100; ++i)
	{
		int s = i;
		int d[100];
		int l[100];
		memset(d, -1, sizeof(d));
		d[i] = 0;
		l[i] = 0;
		for (int c = 1; ; ++c)
		{
			int dl = s * 2 / 100;
			int _s = s * 2 % 100;
			if (d[_s] >= 0)
			{
				startt[i] = d[_s];
				endt[i] = c;
				rel[i] = l[s] + dl - l[_s];
				startl[i] = l[_s];
				endd[i] = _s;
				break;
			}
			l[_s] = l[s] + dl;
			d[_s] = c;
			s = _s;
		}
	}
	int T;
	scanf("%d", &T);
	while (T--)
	{
		long long N, K;
		scanf("%I64d %I64d", &N, &K);
		int t = N % 100;
		N -= t;
		if (K >= endt[t])
		{
			N += (startl[t] + rel[t] * ((K - startt[t]) / (endt[t] - startt[t]))) * 100;
			K -= (K - startt[t]) / (endt[t] - startt[t]) * (endt[t] - startt[t]) + startt[t]; 
			t = endd[t];
		}
		for (int i = 0; i < K; ++i)
		{
			t = t + t % 100;
		}
		printf("%I64d\n", N + t);
	}
	return 0;
}
