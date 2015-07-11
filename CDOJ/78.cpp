#include <cstdio>
#include <algorithm>

using namespace std;

struct Line
{
	int x, y;
	bool operator < (const Line& rhs) const
	{
		return x * rhs.y < y * rhs.x;
	}
};

int gcd(int a, int b)
{
	return !b ? a : gcd(b, a % b);
}

Line line[3000 * 3000];

int main()
{
	int pos = 0;
	for (int i = 1; i <= 3000; ++i)
	{
		for (int j = i + 1; j <= 3000; ++j)
		{
			if (gcd(i, j) == 1)
			{
				line[pos++] = (Line){i, j};
			}
		}
	}
	sort(line, line + pos);
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int n;
		scanf("%d", &n);
		bool first = true;
		for (int i = 0; i < pos; ++i)
		{
			if (line[i].y <= n)
			{
				if (first)
				{
					first = false;
				}
				else
				{
					printf(",");
				}
				printf("%d/%d", line[i].x, line[i].y);
			}
		}
		printf("\n");
	}
	return 0;
}
