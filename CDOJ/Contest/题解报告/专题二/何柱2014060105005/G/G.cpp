#include <cstdio>
#include <cstring>
#include <set>
#include <queue>

using namespace std;

struct Node
{
	int bits;
	int pos;
	bool operator < (const Node& rhs) const
	{
		return bits < rhs.bits || (bits == rhs.bits && pos < rhs.pos);
	}
};

struct Status
{
	Node node;
	int step;
};

int n;
char m[5][6];

inline int idx(int x, int y)
{
	return x * n + y;
}

inline bool isvalid(int x, int y)
{
	return x >= 0 && x < n && y >= 0 && y < n;
}

int main()
{
	while (scanf("%d", &n) == 1 && n)
	{
		int firstbits = 0;
		int firstpos = 0;
		for (int i = 0; i < n; ++i)
		{
			scanf("%s", m[i]);
			for (int j = 0; j < n; ++j)
			{
				if (m[i][j] == '#')
				{
					firstbits += 1 << idx(i, j);
				}
				else if (m[i][j] == '@')
				{
					firstpos = idx(i, j);
				}
			}
		}
		int n2 = n * n;
		queue<Status> q;
		set<Node> s;
		q.push((Status){(Node){firstbits, firstpos}, 0});
		int flag = -1;
		int num[n2];
		while (!q.empty())
		{
			Status p = q.front();
			q.pop();
			int bits = p.node.bits;
			int pos = p.node.pos;
			if (s.count(p.node))
			{
				continue;
			}
			s.insert(p.node);
			int posx = pos / n;
			int posy = pos % n;
			if (bits == 0)
			{
				flag = p.step;
				break;
			}
			memset(num, 0, sizeof num);
			for (int i = 0; i < n; ++i)
			{
				for (int j = 0; j < n; ++j)
				{
					if (bits & (1 << idx(i, j)))
					{
						for (int dx = -1; dx <= 1; ++dx)
						{
							for (int dy = -1; dy <= 1; ++dy)
							{
								if (dx == 0 && dy == 0)
								{
									continue;
								}
								int x = i + dx;
								int y = j + dy;
								if (isvalid(x, y))
								{
									num[idx(x, y)]++;
								}
							}
						}
					}
				}
			}
			for (int i = -1; i <= 1; ++i)
			{
				for (int j = -1; j <= 1; ++j)
				{
					if (i == 0 && j == 0)
					{
						continue;
					}
					int newposx = posx + i;
					int newposy = posy + j;
					if (isvalid(newposx, newposy) && !(bits & (1 << idx(newposx, newposy))))
					{
						for (int dx = -1; dx <= 1; ++dx)
						{
							for (int dy = -1; dy <= 1; ++dy)
							{
								if (dx == 0 && dy == 0)
								{
									continue;
								}
								int newnewposx = newposx + dx;
								int newnewposy = newposy + dy;
								if (isvalid(newnewposx, newnewposy))
								{
									num[idx(newnewposx, newnewposy)]++;
								}
							}
						}
						int newbits = 0;
						for (int j = 0; j < n2; ++j)
						{
							if (j != idx(newposx, newposy) && ((bits & (1 << j) && (num[j] == 2 || num[j] == 3)) || (!(bits & (1 << j)) && num[j] == 3)))
							{
								newbits += 1 << j;
							}
						}
						q.push((Status){(Node){newbits, idx(newposx, newposy)}, p.step + 1});
						for (int dx = -1; dx <= 1; ++dx)
						{
							for (int dy = -1; dy <= 1; ++dy)
							{
								if (dx == 0 && dy == 0)
								{
									continue;
								}
								int newnewposx = newposx + dx;
								int newnewposy = newposy + dy;
								if (isvalid(newnewposx, newnewposy))
								{
									num[idx(newnewposx, newnewposy)]--;
								}
							}
						}
					}
				}
			}
		}
		printf("%d\n", flag);
	}
	return 0;
}
