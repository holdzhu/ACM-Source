#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 100001;
char s[MAXN];
int q;
int n;

int sa[MAXN], t[MAXN], t2[MAXN], c[MAXN], rnk[MAXN];
int height[MAXN];
int kmp[MAXN];
int rmq[20][MAXN];
int prelog[MAXN];

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

void getHeight()
{
	int k = 0;
	for (int i = 0; i < n; ++i)
	{
		rnk[sa[i]] = i;
	}
	for (int i = 0; i < n; ++i)
	{
		if (k)
		{
			k--;
		}
		int j = sa[rnk[i] - 1];
		while (s[i + k] == s[j + k])
		{
			k++;
		}
		rmq[0][rnk[i]] = k;
		height[rnk[i]] = k;
	}
}

void initRMQ()
{
	for (int i = 1; (1 << i) <= n; ++i)  
	{
		for (int j = 0; j + (1 << i) - 1 < n; ++j)
		{
			rmq[i][j] = min(rmq[i - 1][j], rmq[i - 1][j + (1 << (i - 1))]);
		}
	}
}

int main()
{
	scanf("%s", s);
	scanf("%d", &q);
	n = strlen(s);
	for (int i = 0; i < n; ++i)
	{
		s[i] -= 'a';
		s[i]++;
	}
	s[n] = 0;
	n++;
	build_sa(27);
	n--;
	for (int i = 0; i < n; ++i)
	{
		sa[i] = sa[i + 1];
	}
	getHeight();
	initRMQ();
	unsigned int ans = 0;
	for (int i = 0; i < n; ++i)
	{
		int d = 0;
		while ((1 << (d + 1)) <= i) d++;
		prelog[i] = d;
	}
	printf("finish\n");
	for (int i = 0; i < n - 1 - q; ++i)
	{
		for (int j = 1; i + q + j * 2 <= n; ++j)
		{
			int l = rnk[i];
			int r = rnk[i + q + j];
			if (l > r)
			{
				swap(l, r);
			}
			int d = prelog[r - l];
			if (rmq[d][l + 1] >= j && rmq[d][r - (1 << d) + 1] >= j)
			{
				ans++;
			}
		}
	}
	// for (int i = 0; i < n - 1; ++i)
	// {
	// 	int minheight = 1000000000;
	// 	for (int j = i + 1; j < n; ++j)
	// 	{
	// 		minheight = min(minheight, height[j]);
	// 		int l = sa[i];
	// 		int r = sa[j];
	// 		if (l > r)
	// 		{
	// 			swap(l, r);
	// 		}
	// 		if (r - l > q && minheight >= r - l - q)
	// 		{
	// 			ans++;
	// 		}
	// 	}
	// }
	printf("%u\n", ans);
	return 0;
}
