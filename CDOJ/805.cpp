#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
	int N;
	scanf("%d", &N);
	int a[N - N / 2];
	int b[N / 2];
	for (int i = 0; i < N; ++i)
	{
		if (i % 2)
		{
			scanf("%d", &b[i / 2]);
		}
		else
		{
			scanf("%d", &a[i / 2]);
		}
	}
	sort(a, a + N - N / 2);
	sort(b, b + N / 2);
	bool yes = true;
	for (int i = 1; i < N - N / 2; ++i)
	{
		if (a[i] < b[i - 1])
		{
			yes = false;
			break;
		}
	}
	if (yes)
	{
		for (int i = 0; i < N / 2; ++i)
		{
			if (b[i] < a[i])
			{
				yes = false;
				break;
			}
		}
	}
	if (yes)
	{
		printf("Yes\n");
	}
	else
	{
		printf("No\n");
	}
	return 0;
}
