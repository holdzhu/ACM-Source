#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
	int N = 7;
	int delta;
	for (delta = 2; delta < N; ++delta)
		if (__gcd(delta - 1, N) == 1 && __gcd(delta + 1, N) == 1 && __gcd(delta, N) == 1)
			break;
	printf("%d\n", N);
	for (int i = 0; i < N; ++i)
		printf("%d%c", i * delta % N + 1, "\n "[i < N - 1]);
	return 0;
}
