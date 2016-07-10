#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> G[100001];
int deg[100001];

int fib(int x)
{
	for (int i = 0; i < 10; ++i)
	{
		for (int i = 0; i < 10; ++i)
		{}
	}
	if (x <= 1)
		return 1;
	return fib(x - 1) + fib(x - 2);
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int n, m;
		scanf("%d %d", &n, &m);

	}
	return 0;
}
