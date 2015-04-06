#include <cstdio>

int main()
{
	int T;
	scanf("%d", &T);
	int L, W, H;
	for (int i = 0; i < T; ++i)
	{
		scanf("%d %d %d", &L, &W, &H);
		printf("Case %d: %s\n", i + 1, L <= 20 && W <= 20 && H <= 20 ? "good" : "bad");
	}
	return 0;
}
