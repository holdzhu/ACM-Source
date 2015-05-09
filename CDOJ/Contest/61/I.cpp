#include <cstdio>
#include <ctime>
#include <cctype>
#include <cstring>

char s[100001];
int k;
int l = 0;
int next[100001];
unsigned int step[100001];
int n;
char c;
long long hash[100001];
long long pow[100001];
const int sigmasize = 26;

void initHash()
{
	hash[0] = 0;
	pow[0] = 1;
	for (int i = 0; i < l; ++i)
	{
		hash[i + 1] = hash[i] * sigmasize + (s[i] - 'a');
		pow[i + 1] = pow[i] * sigmasize;
	}
}

long long getHash(int l, int r)
{
	return hash[r] - hash[l] * pow[r - l];
}

int main()
{
	while (isalpha(c = getchar()))
	{
		s[l++] = c;
	}
	scanf("%d", &k);
	clock_t start = clock();
	unsigned int ans = 0;
	next[0] = -1;
	step[0] = 0;
	int t0 = l - k - 1;
	int t1 = (l - k) / 2 - 1;
	initHash();
	for (int i = 0; i <= t1; ++i)
	{
		int t2 = i + 1 + k;
		n = i + 1;
		int m = 0;
		for (int j = i - n + 1; j <= i; ++j)
		{
			if (getHash(j, i + 1) == getHash(i + k + 1, i + k + i - j + 2))
			{
				m = i - j + 1;
				break;
			}
		}
		for (int j = 0; j <= m; ++j)
		{
			int q = next[j];
			while (q >= 0 && s[t2 + j] != s[t2 + q])
			{
				q = next[q];
			}
			next[j + 1] = q + 1;
			step[j + 1] = step[q + 1] + 1;
		}
		ans += step[m];
	}
	for (int i = t1 + 1; i < t0; ++i)
	{
		int t2 = i + 1 + k;
		n = l - t2;
		int m = 0;
		for (int j = i - n + 1; j <= i; ++j)
		{
			if (getHash(j, i + 1) == getHash(i + k + 1, i + k + i - j + 2))
			{
				m = i - j + 1;
				break;
			}
		}
		for (int j = 0; j < m; ++j)
		{
			int q = next[j];
			while (q >= 0 && s[t2 + j] != s[t2 + q])
			{
				q = next[q];
			}
			next[j + 1] = q + 1;
			step[j + 1] = step[q + 1] + 1;
		}
		ans += step[m];
	}
	printf("%u\n", ans);
	printf("%f\n", (double)(clock() - start) / CLOCKS_PER_SEC);
	return 0;
}