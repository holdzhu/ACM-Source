#include <cstdio>
#include <algorithm>

using namespace std;

pair<int, int> a[1000];

bool cmp(const pair<int, int> a, const pair<int, int> b)
{
	return a.first * b.second > a.second * b.first;
}

int main()
{
	int M, N;
	while (scanf("%d %d", &M, &N) == 2 && M >= 0 && N >= 0)
	{
		for (int i = 0; i < N; ++i)
		{
			int j, f;
			scanf("%d %d", &j, &f);
			a[i].first = j;
			a[i].second = f;
		}
		sort(a, a + N, cmp);
		double sum = 0;
		for (int i = 0; i < N; ++i)
		{
			if (M >= a[i].second)
			{
				M -= a[i].second;
				sum += a[i].first;
			}
			else
			{
				sum += a[i].first * M * 1.0 / a[i].second;
				break;
			}
		}
		printf("%.3f\n", sum);
	}
	return 0;
}
