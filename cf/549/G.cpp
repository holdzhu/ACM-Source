#include <cstdio>
#include <algorithm>

using namespace std;

int n;
int q[200000];

bool cmp(const int& a, const int& b)
{
	return q[a] + a - b <= q[b] + b - a + n - 2;
}

int p[200000];

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &q[i]);
		p[i] = i;
	}
	sort(p, p + n, cmp);
	for (int i = 0; i < n; ++i)
	{
		q[p[i]] = q[p[i]] + p[i] - i;
		if ((i && q[p[i]] < q[p[i - 1]]) || q[p[i]] < 0)
		{
			printf(":(\n");
			return 0;
		}
	}
	for (int i = 0; i < n; ++i)
	{
		printf("%d ", q[p[i]]);
	}
	printf("\n");
	return 0;
}
