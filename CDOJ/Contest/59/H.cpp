#include <cstdio>
#include <cstdlib>
#include <cstring>

struct Node
{
	int pos, len;
};

Node p[100000];

Node find(int x)
{
	if (x != p[x].pos)
	{
		Node node = find(p[x].pos);
		p[x].pos = node.pos;
		p[x].len += node.len;
	}
	return p[x];
}

int main()
{
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; ++i)
	{
		p[i].pos = i;
		p[i].len = 0;
	}
	char s[3];
	while (scanf("%s", s) == 1 && s[0] != 'O')
	{
		if (s[0] == 'I')
		{
			int x, y;
			scanf("%d %d", &x, &y);
			x--;
			y--;
			Node nodex = find(x);
			Node nodey = find(y);
			if (nodex.pos != nodey.pos)
			{
				p[x].pos = y;
				p[x].len = abs(x - y) % 1000;
			}
		}
		else
		{
			int x;
			scanf("%d", &x);
			x--;
			Node node = find(x);
			printf("%d\n", node.len);
		}
	}
	return 0;
}
