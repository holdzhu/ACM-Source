#include <cstdio>
#include <algorithm>

using namespace std;

char name[11][110];
char vote[11];
int invalid;
int v[11];

int main()
{
	freopen("bad.in", "r", stdin);
	freopen("bad.out", "w", stdout);
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; ++i)
		scanf("%s", name[i]);
	for (int i = 0; i < m; ++i)
	{
		scanf("%s", vote);
		int cnt = 0;
		int last = -1;
		for (int j = 0; j < n; ++j)
		{
			if (vote[j] == 'X')
			{
				cnt++;
				last = j;
			}
		}
		if (cnt == 1)
			v[last]++;
		else
			invalid++;
	}
	vector<pair<int, int> > vec;
	for (int i = 0; i < n; ++i)
		vec.push_back(make_pair(-v[i], i));
	sort(vec.begin(), vec.end());
	for (int i = 0; i < n; ++i)
		printf("%s %.2f%%\n", name[vec[i].second], 100.0 * (-vec[i].first) / m);
	printf("Invalid %.2f%%\n", 100.0 * invalid / m);
	return 0;
}
