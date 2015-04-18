#include <cstdio>
#include <algorithm>

using namespace std;

int ax[1000];
int ay[1000];
int bx[100];
int by[100];
int sbx[101];
int sby[101];

int main()
{
	int T;
	scanf("%d", &T);
	for (int kase = 1; kase <= T; ++kase)
	{
		int N, M, A, B;
		scanf("%d %d %d %d", &N, &M, &A, &B);
		long long a1 = A;
		long long b1 = 0;
		long long c1 = 0;
		long long a2 = A;
		long long b2 = 0;
		long long c2 = 0;
		for (int i = 0; i < A; ++i)
		{
			scanf("%d %d", &ax[i], &ay[i]);
			b1 += ax[i];
			b2 += ay[i];
			c1 += (long long)ax[i] * ax[i];
			c2 += (long long)ay[i] * ay[i];
		}
		b1 *= -2;
		b2 *= -2;
		sbx[0] = 0;
		sby[0] = 0;
		for (int i = 0; i < B; ++i)
		{
			scanf("%d %d", &bx[i], &by[i]);
		}
		sort(bx, bx + B);
		sort(by, by + B);
		for (int i = 0; i < B; ++i)
		{
			sbx[i + 1] = sbx[i] + bx[i];
			sby[i + 1] = sby[i] + by[i];
		}
		long long ansx = 0;

		for (int i = 0; i < B; ++i)
		{
			
		}
	}
	return 0;
}
