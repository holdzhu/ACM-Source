#include <cstdio>
#include <cstring>

char s[100001];
int K, l;
const int sigmasize = 26;
const long long mod = 1000000007;
long long hash1[100001];
long long hash2[100001];
long long pow1[100001];
long long pow2[100001];

inline int min(int a, int b)
{
	return a < b ? a : b;
}

inline int idx(char c)
{
	return c - 'a';
}

void initHash()
{
	hash1[0] = hash2[0] = 0;
	pow1[0] = pow2[0] = 1;
	for (int i = 0; i < l; ++i)
	{
		pow1[i + 1] = pow1[i] * sigmasize;
		pow2[i + 1] = pow2[i] * sigmasize;
		pow2[i + 1] %= mod;
		hash1[i + 1] = hash1[i] * sigmasize + idx(s[i]);
		hash2[i + 1] = hash2[i] * sigmasize + idx(s[i]);
		hash2[i + 1] %= mod;
	}
}

long long getHash1(int l, int r)
{
	return hash1[r] - hash1[l] * pow1[r - l];
}

long long getHash2(int l, int r)
{
	long long rnt = (hash2[r] - hash2[l] * pow2[r - l] % mod) % mod;
	if (rnt < 0)
	{
		rnt += mod;
	}
	return rnt;
}

int rightLCP(int s1, int s2, int R)
{
	if (s2 + R > l)
	{
		R = l - s2;
	}
	int L = 1;
	while (L < R)
	{
		int M = (L + R + 1) >> 1;
		if (getHash1(s1, s1 + M) == getHash1(s2, s2 + M) && getHash2(s1, s1 + M) == getHash2(s2, s2 + M))
		{
			L = M;
		}
		else
		{
			R = M - 1;
		}
	}
	return L;
}

int leftLCP(int s1, int s2, int R)
{
	if (s1 - R + 1 < 0)
	{
		R = s1 + 1;
	}
	int L = 1;
	while (L < R)
	{
		int M = (L + R + 1) >> 1;
		if (getHash1(s1 - M + 1, s1 + 1) == getHash1(s2 - M + 1, s2 + 1) && getHash2(s1 - M + 1, s1 + 1) == getHash2(s2 - M + 1, s2 + 1))
		{
			L = M;
		}
		else
		{
			R = M - 1;
		}
	}
	return L;
}

int main()
{
	scanf("%s", s);
	scanf("%d", &K);
	l = strlen(s);
	initHash();
	long long ans = 0;
	for (int i = 1; i * 2 + K <= l; ++i)
	{
		for (int j = 0; j + i + K < l; j += i + K)
		{
			for (int k = j; k < i + j + K && k + i + K < l; k += i)
			{
				if (s[k] == s[k + i + K])
				{
					int l1 = leftLCP(k, k + i + K, i);
					int l2 = rightLCP(k, k + i + K, min(i, i + j + K - k));
					if (l1 + l2 - i > 0)
					{
						ans += l1 + l2 - i;
					}
				}
			}
		}
	}
	printf("%lld\n", ans);
	return 0;
}
