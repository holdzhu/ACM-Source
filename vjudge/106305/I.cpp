#include <cstdio>
#include <algorithm>

using namespace std;

int k[10000];

int main()
{
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; ++i)
		scanf("%d", &k[i]);
	sort(k, k + N);
	long long mx = 0;
	for (int i = 0; i < N; ++i)
	{
		if (k[i] > mx + 1)
			break;
		else
			mx += k[i];
	}
	printf("%lld\n", mx + 1);
	return 0;
}
