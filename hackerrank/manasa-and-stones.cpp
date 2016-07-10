#include <cstdio>
#include <set>

using namespace std;

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int n, a, b;
		scanf("%d %d %d", &n, &a, &b);
		set<int> s;
		for (int i = 0; i <= n - 1; ++i)
			s.insert(a * i + b * (n - 1 - i));
		for (int v: s)
			printf("%d ", v);
		puts("");
	}
	return 0;
}
