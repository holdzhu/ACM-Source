#include <cstdio>
#include <map>

using namespace std;

int main()
{
	int N;
	while (scanf("%d", &N) == 1)
	{
		map<int, int> m;
		for (int i = 0; i < N; ++i)
		{
			int t = 0;
			scanf("%d", &t);
			if (!m.count(t))
			{
				m[t] = 0;
			}
			m[t]++;
		}
		for (map<int, int>::iterator i = m.begin(); i != m.end(); ++i)
		{
			if (i->second > N / 2)
			{
				printf("%d\n", i->first);
				break;
			}
		}
	}
	return 0;
}
