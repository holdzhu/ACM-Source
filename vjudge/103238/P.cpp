#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 1e5;

int tree[maxn << 2];
bool lazy[maxn << 2];

void push_up(int rt, int l, int r)
{
	tree[rt] = tree[rt << 1] + tree[rt << 1 | 1];
	if (lazy[rt])
		tree[rt] = r - l + 1 - tree[rt];
}

void update(int L, int R, int rt, int l, int r)
{
	if (L <= l && r <= R)
	{
		tree[rt] = r - l + 1 - tree[rt];
		lazy[rt] ^= 1;
		return;
	}
	int m = (l + r) >> 1;
	if (m >= L)
		update(L, R, rt << 1, l, m);
	if (m < R)
		update(L, R, rt << 1 | 1, m + 1, r);
	push_up(rt, l, r);
}

const int P = 880803841;
const int G = 26;
const int NUM = 20;
long long wn[NUM];

long long pow_mod(long long a, long long k)
{
	long long s = 1;
	a %= P;
	while (k)
	{
		if (k & 1)
			s = s * a % P;
		a = a * a % P;
		k >>= 1;
	}
	return s;
}

void get_wn()
{
	for (int i = 0; i < NUM; ++i)
		wn[i] = pow_mod(G, (P - 1) / (1 << i));
}

void rader(long long a[], int len)
{
	int j = len >> 1;
	for (int i = 1; i < len - 1; ++i)
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

void NTT(long long a[], int len, int on)
{
	rader(a, len);
	int id = 0;
	for (int h = 2; h <= len; h <<= 1)
	{
		id++;
		for (int j = 0; j < len; j += h)
		{
			long long w = 1;
			for (int k = j; k < j + h / 2; ++k)
			{
				long long u = a[k] % P;
				long long t = w * a[k + h / 2] % P;
				a[k] = (u + t) % P;
				a[k + h / 2] = (u - t + P) % P;
				w = w * wn[id] % P;
			}
		}
	}
	if (on == -1)
	{
		for (int i = 1; i < len / 2; ++i)
			swap(a[i], a[len - i]);
		long long inv = pow_mod(len, P - 2);
		for (int i = 0; i < len; ++i)
			a[i] = a[i] * inv % P;
	}
}

long long a[1 << 18], b[1 << 18];
long long inv[1 << 18];

int main()
{
	inv[1] = 1;
	for (int i = 2; i < (1 << 18); ++i)
		inv[i] = inv[P % i] * (P - P / i) % P;
	get_wn();
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int N, M, D;
		scanf("%d %d %d", &N, &M, &D);
		int len = 1;
		while (len <= 2 * M)
			len <<= 1;
		a[0] = 1;
		b[0] = 0;
		for (int i = 1; i < len / 2; ++i)
		{
			a[i] = a[i - 1] * inv[i] % P;
			b[i] = a[i] * pow_mod(i, N) % P;
		}
		for (int i = len / 2; i < len; ++i)
			a[i] = b[i] = 0;
		for (int i = 1; i < len / 2; i += 2)
			a[i] = (P - a[i]) % P;
		NTT(a, len, 1);
		NTT(b, len, 1);
		for (int i = 0; i < len; ++i)
			a[i] = a[i] * b[i] % P;
		NTT(a, len, -1);
		memset(tree, 0, sizeof(int) * (M << 2));
		memset(lazy, 0, sizeof(bool) * (M << 2));
		while (D--)
		{
			int l, r;
			scanf("%d %d", &l, &r);
			update(l - 1, r - 1, 1, 0, M - 1);
			printf("%lld\n", a[M - tree[1]]);
		}
	}
	return 0;
}
