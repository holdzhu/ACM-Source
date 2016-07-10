#include <cstdio>
#include <algorithm>

using namespace std;

const int P = (7 << 20) + 1;
const int G = 6;

int w[21][1 << 19];

int quick_mod(int a, int b)
{
	int ans = 1;
	while (b)
	{
		if (b & 1)
			ans = (long long)ans * a % P;
		a = (long long)a * a % P;
		b >>= 1;
	}
	return ans;
}

void Rader(int a[], int len)
{
	int j = len >> 1;
	for (int i = 1; i < len - 1; i++)
	{
		if (i < j)
			swap(a[i], a[j]);
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

void NTT(int a[], int len, int on)
{
	Rader(a, len);
	for (int h = 2, id = 1; h <= len; h <<= 1, ++id)
	{
		for (int j = 0; j < len; j += h)
		{
			for (int k = j; k < j + h / 2; k++)
			{
				int u = a[k];
				int t = (long long)w[id][k - j] * a[k + h / 2] % P;
				a[k] = u + t;
				if (a[k] >= P)
					a[k] -= P;
				a[k + h / 2] = u - t + P;
				if (a[k + h / 2] >= P)
					a[k + h / 2] -= P;
			}
		}
	}
}

int f[1 << 20];

int main()
{
	int n, k;
	scanf("%d %d", &n, &k);
	int mx = 0;
	for (int i = 0; i < n; ++i)
	{
		int a;
		scanf("%d", &a);
		mx = max(mx, a);
		f[a] = 1;
	}
	mx *= k;
	int m = 0;
	while ((1 << m) < mx + 1)
		++m;
	int len = 1 << m;
	for (int i = 0; i <= m; i++)
	{
		int t = 1 << i;
		w[i][0] = 1;
		w[i][1] = quick_mod(G, (P - 1) / t);
		for (int j = 2; j < (1 << (m - 1)); ++j)
			w[i][j] = (long long)w[i][j - 1] * w[i][1] % P;
	}
	NTT(f, len, 1);
	for (int i = 0; i < len; ++i)
		f[i] = quick_mod(f[i], k);
	NTT(f, len, -1);
	for (int i = 1; i < len / 2; i++)
		swap(f[i], f[len - i]);
	for (int i = 0; i <= mx; ++i)
		if (f[i])
			printf("%d ", i);
	return 0;
}
