#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

struct Command
{
	char type;
	int a;
	int b;
};

Command commands[1000000];
int C[1000001];
int cc = 0;
vector<int> v;
map<int, int> m;

int lowbit(int x)
{
	return x & (-x);
}

int sum(int x)
{
	int ret = 0;
	while (x > 0)
	{
		ret += C[x];
		x -= lowbit(x);
	}
	return ret;
}

void add(int x, int d)
{
	while (x <= v.size())
	{
		C[x] += d;
		x += lowbit(x);
	}
}

int main()
{
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; ++i)
	{
		char type;
		int a;
		int b;
		scanf(" %c %d %d", &type, &a, &b);
		commands[cc++] = (Command) {type, a, b};
		v.push_back(a);
		v.push_back(b);
	}
	v.push_back(0);
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	for (int i = 0; i < v.size(); ++i)
	{
		m[v[i]] = i;
	}
	for (int i = 0; i < N; ++i)
	{
		if (commands[i].type == '+')
		{
			m[commands[i].a] +=
		}
	}
	return 0;
}
