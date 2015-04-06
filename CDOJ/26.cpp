#include <cstdio>
#include <algorithm>
using namespace std;

struct Pillar
{
	int X, H;
	bool operator < (const Pillar b) const
	{
		return X < b.X;
	}
};

int main()
{
	int N;
	while (scanf("%d", &N) == 1 && N)
	{
		Pillar pillar[N];
		for (int i = 0; i < N; ++i)
		{
			int X, H;
			scanf("%d%d", &X, &H);
			pillar[i].X = X;
			pillar[i].H = H;
		}
		sort(pillar, pillar + N);
		int T, A;
		scanf("%d/%d", &T, &A);
		int ans = 0;
		int maxx = 0;
		for (int i = 0; i < N; ++i)
		{
			pillar[i].X *= T;
			pillar[i].H *= A;
			if (pillar[i].X + pillar[i].H > maxx)
			{
				maxx = pillar[i].X + pillar[i].H;
				ans++;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
