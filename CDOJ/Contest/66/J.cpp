#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const long long mod = 1000000007;

struct Hash
{
	long long A;
	long long B;
	bool operator == (const Hash& rhs)
	{
		return A == rhs.A && B == rhs.B;
	}
	bool operator < (const Hash& rhs) const
	{
		return A < rhs.A || (A == rhs.A && B < rhs.B);
	}
};

Hash A[100000];
Hash B[100000];

char s[16];

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%s", s);
		int l = strlen(s);
		A[i].A = 0;
		A[i].B = 0;
		for (int j = 0; j < l; ++j)
		{
			A[i].A = A[i].A * 129 + s[j];
			A[i].B = (A[i].B * 129 % mod + s[j]) % mod;
		}
	}
	for (int i = 0; i < n; ++i)
	{
		scanf("%s", s);
		int l = strlen(s);
		B[i].A = 0;
		B[i].B = 0;
		for (int j = 0; j < l; ++j)
		{
			B[i].A = B[i].A * 129 + s[j];
			B[i].B = (B[i].B * 129 % mod + s[j]) % mod;
		}
	}
	sort(A, A + n);
	sort(B, B + n);
	int posa = 0;
	int posb = 0;
	int ans = 0;
	while (posa < n && posb < n)
	{
		if (A[posa] == B[posb])
		{
			ans++;
			posa++;
			posb++;
		}
		else if (A[posa] < B[posb])
		{
			posa++;
		}
		else
		{
			posb++;
		}
	}
	printf("%d\n", ans);
	return 0;
}
