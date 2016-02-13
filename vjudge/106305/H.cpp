#include <cstdio>

int N, M;
int l[100010];
int nxt[100010];

bool check(int x)
{
	int mil = 0, mir = 1e9;
	for (int i = 0, j = 0, s = 0; i < N * 2; ++i)
	{
		while (j < N * 2 && s + l[j] <= x)
			s += l[j++];
		if (i < N && mir - mil > j - i)
			mir = j, mil = i;
		nxt[i] = j;
		s -= l[i];
	}
	for (int i = mil; i <= mir; ++i)
	{
		int t = i % N;
		int cnt = 0;
		while (t < i % N + N)
		{
			t = nxt[t];
			cnt++;
		}
		if (cnt <= M)
			return true;
	}
	return false;
}

int main()
{
	scanf("%d %d", &N, &M);
	int L = 0;
	int R = 0;
	for (int i = 0; i < N; ++i)
	{
		scanf("%d", &l[i]);
		l[N + i] = l[i];
		if (L < l[i])
			L = l[i];
		R += l[i];
	}
	while (L < R)
	{
		int M = (L + R) >> 1;
		if (check(M))
			R = M;
		else
			L = M + 1;
	}
	printf("%d\n", L);
	return 0;
}
