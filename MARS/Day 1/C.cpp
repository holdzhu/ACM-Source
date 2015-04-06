#include <cstdio>
#include <queue>

using namespace std;

struct Point
{
	int x, y, z;
};

struct Step
{
	int time;
	Point point;
};

int main()
{
	int L, R, C;
	while (scanf("%d %d %d", &L, &R, &C) && L && R && C)
	{
		Step startStep;
		startStep.time = 0;
		char a[L][R][C + 1];
		bool h[L][R][C];
		for (int i = 0; i < L; ++i)
		{
			for (int j = 0; j < R; ++j)
			{
				scanf("%s", a[i][j]);
				for (int k = 0; k < C; ++k)
				{
					if (a[i][j][k] == 'S')
					{
						startStep.point.x = i;
						startStep.point.y = j;
						startStep.point.z = k;
						h[i][j][k] = true;
					}
					else
					{
						h[i][j][k] = false;
					}
				}
			}
		}
		queue<Step> q;
		q.push(startStep);
		bool flag = false;
		while (!q.empty())
		{
			Step s = q.front();
			q.pop();
			if (a[s.point.x][s.point.y][s.point.z] == 'E')
			{
				printf("Escaped in %d minute(s).\n", s.time);
				flag = true;
				break;
			}
			if (s.point.x > 0 && a[s.point.x - 1][s.point.y][s.point.z] != '#' && !h[s.point.x - 1][s.point.y][s.point.z])
			{
				Step _s;
				_s.point.x = s.point.x - 1;
				_s.point.y = s.point.y;
				_s.point.z = s.point.z;
				_s.time = s.time + 1;
				h[_s.point.x][_s.point.y][_s.point.z] = true;
				q.push(_s);
			}
			if (s.point.x < L - 1 && a[s.point.x + 1][s.point.y][s.point.z] != '#' && !h[s.point.x + 1][s.point.y][s.point.z])
			{
				Step _s;
				_s.point.x = s.point.x + 1;
				_s.point.y = s.point.y;
				_s.point.z = s.point.z;
				_s.time = s.time + 1;
				h[_s.point.x][_s.point.y][_s.point.z] = true;
				q.push(_s);
			}
			if (s.point.y > 0 && a[s.point.x][s.point.y - 1][s.point.z] != '#' && !h[s.point.x][s.point.y - 1][s.point.z])
			{
				Step _s;
				_s.point.x = s.point.x;
				_s.point.y = s.point.y - 1;
				_s.point.z = s.point.z;
				_s.time = s.time + 1;
				h[_s.point.x][_s.point.y][_s.point.z] = true;
				q.push(_s);
			}
			if (s.point.y < R - 1 && a[s.point.x][s.point.y + 1][s.point.z] != '#' && !h[s.point.x][s.point.y + 1][s.point.z])
			{
				Step _s;
				_s.point.x = s.point.x;
				_s.point.y = s.point.y + 1;
				_s.point.z = s.point.z;
				_s.time = s.time + 1;
				h[_s.point.x][_s.point.y][_s.point.z] = true;
				q.push(_s);
			}
			if (s.point.z > 0 && a[s.point.x][s.point.y][s.point.z - 1] != '#' && !h[s.point.x][s.point.y][s.point.z - 1])
			{
				Step _s;
				_s.point.x = s.point.x;
				_s.point.y = s.point.y;
				_s.point.z = s.point.z - 1;
				_s.time = s.time + 1;
				h[_s.point.x][_s.point.y][_s.point.z] = true;
				q.push(_s);
			}
			if (s.point.z < C - 1 && a[s.point.x][s.point.y][s.point.z + 1] != '#' && !h[s.point.x][s.point.y][s.point.z + 1])
			{
				Step _s;
				_s.point.x = s.point.x;
				_s.point.y = s.point.y;
				_s.point.z = s.point.z + 1;
				_s.time = s.time + 1;
				h[_s.point.x][_s.point.y][_s.point.z] = true;
				q.push(_s);
			}
		}
		if (!flag)
		{
			printf("Trapped!\n");
		}
	}
	return 0;
}
