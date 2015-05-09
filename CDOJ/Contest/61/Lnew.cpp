#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 400002;
char s[MAXN];
int k;
int n;

int sa[MAXN], t[MAXN], t2[MAXN], c[MAXN];
int kmp[MAXN];

void build_sa(int m)
{
	int i, *x = t, *y = t2;
	for (i = 0; i < m; ++i) c[i] = 0;
	for (i = 0; i < n; ++i) c[x[i] = s[i]]++;
	for (i = 1; i < m; ++i) c[i] += c[i - 1];
	for (i = n - 1; i >= 0; --i) sa[--c[x[i]]] = i;
	for (int k = 1; k <= n; k <<= 1)
	{
		int p = 0;
		for (i = n - k; i < n; ++i) y[p++] = i;
		for (i = 0; i < n; ++i) if (sa[i] >= k) y[p++] = sa[i] - k;
		for (i = 0; i < m; ++i) c[i] = 0;
		for (i = 0; i < n; ++i) c[x[y[i]]]++;
		for (i = 1; i < m; ++i) c[i] += c[i - 1];
		for (i = n - 1; i >= 0; --i) sa[--c[x[y[i]]]] = y[i];
		swap(x, y);
		p = 1; x[sa[0]] = 0;
		for (i = 1; i < n; ++i)
			x[sa[i]] = y[sa[i - 1]] == y[sa[i]] && y[sa[i - 1] + k] == y[sa[i] + k] ? p - 1 : p++;
		if (p >= n) break;
		m = p;
	}
}

int main()
{
	scanf("%s %d", s, &k);
	n = strlen(s);
	kmp[0] = -1;
	for (int i = 0; i < n; ++i)
	{
		int q = kmp[i];
		while (q >= 0 && s[q] != s[i])
		{
			q = kmp[q];
		}
		kmp[i + 1] = q + 1;
	}
	if (n % (n - kmp[n]) == 0)
	{
		n = n - kmp[n];
	}
	for (int i = 0; i < n; ++i)
	{
		s[i] -= 'a';
	}
	memcpy(s + n, s, n * sizeof(char));
	n *= 2;
	build_sa(26);
	n /= 2;
	int kth = -1;
	for (int i = 0; i < n * 2; ++i)
	{
		if (sa[i] < n)
		{
			if (sa[i] == k % n)
			{
				break;
			}
			kth++;
		}
	}
	printf("%d %d %d\n", kth + 1, 1, n - kth - 2);
	return 0;
}
