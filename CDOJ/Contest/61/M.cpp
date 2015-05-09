#include <cstdio>
#include <cctype>
#include <cstring>

char s[2000001];
int l;
int ans[2000001];
const long long mod = 1000000007;
const int sigmasize = 62;
long long hash1[2000001];
long long hash2[2000001];
long long hashinv1[2000001];
long long hashinv2[2000001];
long long pow1[2000001];
long long pow2[2000001];

inline int idx(char c)
{
	if (isdigit(c))
	{
		return c - '0';
	}
	if (isupper(c))
	{
		return c - 'A' + 10;
	}
	return c - 'a' + 36;
}

inline bool isequal(int l1, int r1, int l2, int r2)
{
	long long hash11 = (hash1[r1] - hash1[l1] * pow1[r1 - l1]);
	long long hash12 = (hashinv1[l - l2] - hashinv1[l - r2] * pow1[r2 - l2]);
	long long hash21 = (hash2[r1] - hash2[l1] * pow2[r1 - l1] % mod) % mod;
	long long hash22 = (hashinv2[l - l2] - hashinv2[l - r2] * pow2[r2 - l2] % mod) % mod;
	if (hash21 < 0)
	{
		hash21 += mod;
	}
	if (hash22 < 0)
	{
		hash22 += mod;
	}
	return hash11 == hash12 && hash21 == hash22;
}

inline void initHash()
{
	hash1[0] = 0;
	hash2[0] = 0;
	hashinv1[0] = 0;
	hashinv2[0] = 0;
	pow1[0] = 1;
	pow2[0] = 1;
	for (int i = 0; i < l; ++i)
	{
		pow1[i + 1] = pow1[i] * sigmasize;
		pow2[i + 1] = pow2[i] * sigmasize % mod;
		hash1[i + 1] = hash1[i] * sigmasize + idx(s[i]);
		hash2[i + 1] = (hash2[i] * sigmasize % mod + idx(s[i])) % mod;
		hashinv1[i + 1] = hashinv1[i] * sigmasize + idx(s[l - i - 1]);
		hashinv2[i + 1] = (hashinv2[i] * sigmasize % mod + idx(s[l - i - 1])) % mod;
	}
}

int main()
{
	scanf("%s", s);
	l = strlen(s);
	initHash();
	ans[0] = 0;
	long long sum = 0;
	for (int i = 0; i < l; ++i)
	{
		int half = (i + 1) / 2;
		if (isequal(0, half, i - half + 1, i + 1))
		{
			ans[i + 1] = ans[half] + 1;
		}
		else
		{
			ans[i + 1] = 0;
		}
		sum += ans[i + 1];
	}
	printf("%lld\n", sum);
	return 0;
}
