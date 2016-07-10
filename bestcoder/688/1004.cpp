#include <cstdio>

int a[20];
long long r;

void gcd(long long a, long long b, long long &x, long long &y)
{
	if (b == 0)
	{
		x = 1;
		y = 0;
		r = a;
		return;
	}
	gcd(b, a % b, x, y);
	long long t = x;
	x			= y;
	y			= t - a / b * y;
}
long long CRT2(long long b[], long long n[], int m)
{
	int f		 = 0;
	long long n1 = n[0], n2, b1 = b[0], b2, c, t, k, x, y;
	for (int i = 1; i < m; i++)
	{
		n2 = n[i];
		b2 = b[i];
		c  = b2 - b1;
		gcd(n1, n2, x, y);
		if (c % r != 0)
		{
			f = 1;
			break;
		}
		k  = c / r * x;
		t  = n2 / r;
		k  = (k % t + t) % t;
		b1 = b1 + n1 * k;
		n1 = n1 * t;
	}
	if (f)
		return -1;
	return b1;
}

long long A[20], M[20];
bool vis[20];

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int N;
		scanf("%d", &N);
		for (int i = 0; i < N; ++i)
		{
			int t;
			scanf("%d", &t);
			--t;
			a[t] = i;
			vis[i] = 0;
		}
		int pos = N - 1;
		for (int i = 0; i < N; ++i)
		{
			int cnt = 0;
			do
			{
				cnt++;
				pos = (pos + 1) % N;
				while (vis[pos])
					pos = (pos + 1) % N;
			} while (pos != a[i]);
			vis[a[i]] = true;
			A[i]	  = cnt - 1;
			M[i]	  = N - i;
		}
		long long ans = CRT2(A, M, N);
		for (int i = 0; i < N; ++i)
		{
			if (ans % M[i] != A[i])
			{
				ans = -1;
				break;
			}
		}
		if (ans == -1)
			puts("Creation August is a SB!");
		else
			printf("%I64d\n", ans + 1);
	}
	return 0;
}