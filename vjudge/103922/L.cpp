#include <cstdio>
#include <algorithm>

using namespace std;

int pre[64];
long long C[64][64];
int X;

long long solve(int d, bool limit, int cnt, long long target)
{
	if (d == -1)
		return pre[cnt] + 1 == X;
	if (limit)
	{
		long long sum = 0;
		for (int i = 0; i + cnt < 64; ++i)
			if (pre[i + cnt] + 1 == X)
				sum += C[d + 1][i];
		return sum;
	}
	if (target >> d & 1)
		return solve(d - 1, 0, cnt + 1, target) + solve(d - 1, 1, cnt, target);
	else
		return solve(d - 1, 0, cnt, target);
}

int main()
{
	pre[1] = 0;
	for (int i = 2; i < 64; ++i)
		pre[i] = pre[__builtin_popcount(i)] + 1;
	for (int i = 0; i < 64; ++i)
	{
		printf("%d\n", pre[i]);
	}
	C[0][0] = 1;
	for (int i = 1; i < 64; ++i)
	{
		C[i][0] = 1;
		for (int j = 1; j < i; ++j)
			C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
		C[i][i] = 1;
	}
	long long l, r;
	while (scanf("%I64d %I64d %d", &l, &r, &X) == 3)
	{
		if (X == 0)
			puts(l == 1 ? "1" : "0");
		else
			printf("%I64d\n", solve(6, 0, 0, r));
	}
	return 0;
}
