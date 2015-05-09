#include <cstdio>

char a[1999999];
char b[1999999];
int next[2000000];

int main()
{
	int N, M, last, t;
	scanf("%d", &N);
	scanf("%d", &last);
	for (int i = 0; i < N - 1; ++i)
	{
		scanf("%d", &t);
		a[i] = t - last;
		last = t;
	}
	scanf("%d", &M);
	scanf("%d", &last);
	for (int i = 0; i < M - 1; ++i)
	{
		scanf("%d", &t);
		b[i] = t - last;
		last = t;
	}
	next[0] = -1;
	int q;
	for (int i = 0; i < M - 1; ++i)
	{
		q = next[i];
		while (q >= 0 && b[q] != b[i])
		{
			q = next[q];
		}
		next[i + 1] = q + 1;
	}
	q = 0;
	int flag = 0;
	for (int i = 0; i < N - 1; ++i)
	{
		while (q >= 0 && b[q] != a[i])
		{
			q = next[q];
		}
		q++;
		if (q == M - 1)
		{
			flag++;
		}
	}
	if (flag)
	{
		printf("Wow! Life Winner!\n%d\n", flag);
	}
	else
	{
		printf("Oh. That's impossible. I must have had a dream.\n");
	}
	return 0;
}
