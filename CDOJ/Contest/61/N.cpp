#include <cstdio>
#include <cstring>

const int sigmasize = 62;
const int hash1size = 100007;
int a[hash1size];
char s[101];

inline int idx(char c)
{
	if (c >= 'A' && c <= 'Z')
	{
		return c - 'A';
	}
	else if (c >= 'a' && c <= 'z')
	{
		return c - 'a' + 26;
	}
	else
	{
		return c - '0' + 52;
	}
}

inline void insert(int hash1, int hash2)
{
	if (hash2 == -1)
	{
		hash2 = -2;
	}
	while (a[hash1] != -1 && a[hash1] != hash2)
	{
		hash1 += 1007;
		hash1 %= hash1size;
	}
	a[hash1] = hash2;
}

int main()
{
	memset(a, -1, sizeof a);
	for (int i = 0; i < 20000; ++i)
	{
		scanf("%s", s);
		int hash1 = 0;
		int hash2 = 0;
		for (int j = 0; j < 100; ++j)
		{
			hash1 *= sigmasize;
			hash1 %= hash1size;
			hash1 += idx(s[j]);
			hash1 %= hash1size;
			hash2 *= sigmasize;
			hash2 += idx(s[j]);
		}
		insert(hash1, hash2);
	}
	int ans = 0;
	for (int i = 0; i < hash1size; ++i)
	{
		if (a[i] != -1)
		{
			ans++;
		}
	}
	printf("%d\n", ans);
}
