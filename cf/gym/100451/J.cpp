#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

struct Node
{
	int num;
	int k;
	bool operator < (const Node& rhs) const
	{
		return num < rhs.num;
	}
};

int c[1000001];
int delta[1000001];

int main()
{
	int n, t;
	scanf("%d %d", &n, &t);
	priority_queue<Node> pq;
	long long ans = 0;
	int k = 1;
	c[1] = n;
	for (int i = 1; i <= n; ++i)
	{
		pq.push((Node){i, 1});
		ans += i;
	}
	while (1)
	{
		k++;
		c[k] = 0;
		long long newans = ans + t;
		for (c[k] = 0; 1 + c[k] * k < pq.top().num; ++c[k])
		{
			Node node = pq.top();
			pq.pop();
			pq.push((Node){1 + c[k] * k, k});
			newans -= node.num;
			newans += 1 + c[k] * k;
			delta[c[k]] = node.k;
		}
		if (newans >= ans)
		{
			break;
		}
		for (int i = 0; i < c[k]; ++i)
		{
			c[delta[i]]--;
		}
		ans = newans;
	}
	int cnt = 0;
	printf("%I64d\n%d\n", ans, k - 2);
	for (int i = 1; i < k - 1; ++i)
	{
		cnt += c[i];
		printf("%d ", cnt);
	}
	printf("\n");
	return 0;
}
