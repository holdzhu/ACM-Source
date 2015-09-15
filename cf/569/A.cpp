#include <cstdio>

int main()
{
	int T, S, q;
	scanf("%d %d %d", &T, &S, &q);
	long long t = S;
	int cnt = 0;
	while (t < T)
	{
		cnt++;
		t *= q;
	}
	printf("%d\n", cnt);
	return 0;
}
