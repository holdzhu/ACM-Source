#include <cstdio>
#include <vector>

using namespace std;

int a[100000];
vector<int> event[1001];

int main()
{
	int n;
	scanf("%d", &n);
	int mx = 0;
	int sum = 0;
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &a[i]);
		if (mx < a[i])
			mx = a[i];
	}
	for (int i = 0; i < n; ++i)
	{
		int t = a[i];
		while (t < mx)
		{
			sum++;
			t <<= 1;
		}
	}
	printf("%d\n", mx + sum);
	if (mx + sum <= 1000)
	{
		for (int i = 0; i < n; ++i)
		{
			while (a[i] * 2 <= mx)
			{
				a[i] <<= 1;
				printf("science mission to the planet %d\n", i + 1);
			}
			if (a[i] != mx)
				event[a[i] * 2 - mx].push_back(i);
		}
		for (int i = 1; i <= mx; ++i)
		{
			puts("flying mission");
			for (int j = 0; j < event[i].size(); ++j)
				printf("science mission to the planet %d\n", event[i][j] + 1);
		}
	}
	return 0;
}
