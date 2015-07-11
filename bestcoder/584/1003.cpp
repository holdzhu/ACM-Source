#include <cstdio>
#include <set>

using namespace std;

unsigned int s[1000];

unsigned int read()
{
	int a, b, c, d;
	scanf("%d.%d.%d.%d", &a, &b, &c, &d);
	return (a << 24) + (b << 16) + (c << 8) + d;
}

int main()
{
	int T;
	scanf("%d", &T);
	for (int kase = 0; kase < T; ++kase)
	{
		int N, M;
		scanf("%d %d", &N, &M);
		for (int i = 0; i < N; ++i)
		{
			s[i] = read();
		}
		printf("Case #%d:\n", kase + 1);
		for (int i = 0; i < M; ++i)
		{
			int t = read();
			set<int> se;
			for (int j = 0; j < N; ++j)
			{
				se.insert(t & s[j]);
			}
			printf("%u\n", se.size());
		}
	}
	return 0;
}
