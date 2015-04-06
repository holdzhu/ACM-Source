#include <cstdio>
#include <set>

using namespace std;

int main()
{
	int N;
	scanf("%d", &N);
	int x[N], y[N];
	for (int i = 0; i < N; ++i)
	{
		scanf("%d %d", &x[i], &y[i]);
	}
	set<double> s;
	int flag = 0;
	for (int i = 1; i < N; ++i)
	{
		if (x[i] == x[0])
		{
			s.insert(1e10);
			if (s.size() == 2 && flag == 0)
			{
				flag = i;
			}
		}
		else
		{
			s.insert((y[i] - y[0]) * 1.0 / (x[i] - x[0]));
			if (s.size() == 2 && flag == 0)
			{
				flag = i;
			}
		}
	}
	if (s.size() == 2)
	{
		printf("%d %d\n", x[flag], y[flag]);
	}
	else
	{
		printf("%d %d\n", x[0], y[0]);
	}
	return 0;
}
