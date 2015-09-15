#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int x[1000001];
int y[1000001];

vector<pair<int, int> > blocks[1000];


int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d %d", &x[i], &y[i]);
		int b = x[i] / 1000;
		int len = 1000;
		if (b >= 999)
		{
			b = 999;
			len = 1001;
		}
		int w = 0;
		if (b % 2 == 0)
		{
			if (y[i] % 2 == 0)
			{
				w = y[i] * len + (x[i] - b * 1000);
			}
			else
			{
				w = y[i] * len + (len - (x[i] - b * 1000) - 1);
			}
		}
		else
		{
			if (y[i] % 2 == 0)
			{
				w = (1000000 - y[i]) * len + (x[i] - b * 1000);
			}
			else
			{
				w = (1000000 - y[i]) * len + (len - (x[i] - b * 1000) - 1);
			}
		}
		blocks[b].push_back(make_pair(w, i));
	}
	for (int i = 0; i < 1000; ++i)
	{
		sort(blocks[i].begin(), blocks[i].end());
		for (int j = 0; j < blocks[i].size(); ++j)
		{
			printf("%d ", blocks[i][j].second + 1);
		}
	}
	printf("\n");
	return 0;
}
