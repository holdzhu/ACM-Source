#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
	int N, Q;
	scanf("%d %d", &N, &Q);
	int mi = 1e9;
	int mx = -1e9;
	for (int i = 0; i < N; ++i)
	{
		int A;
		scanf("%d", &A);
		mi = min(mi, A);
		mx = max(mx, A);
	}
	while (Q--)
	{
		int t;
		scanf("%d", &t);
		puts(t >= mi && t <= mx ? "Yes" : "No");
	}
	return 0;
}
