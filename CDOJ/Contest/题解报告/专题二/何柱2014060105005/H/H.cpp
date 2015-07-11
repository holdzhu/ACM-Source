#include <cstdio>
#include <cstring>

const int pow[] = {1, 3, 9, 27, 81, 243, 729, 2187, 6561};
enum Status
{
	INVALID = -1,
	WIN,
	LOSE,
	UNKNOWN
};
Status f[19683];

inline int idx(int x, int y)
{
	return x * 3 + y;
}

Status dfs(int tris)
{
	if (f[tris] != INVALID)
	{
		return f[tris];
	}
	int tri[3][3];
	int Os = 0;
	int Xs = 0;
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			tri[i][j] = tris / pow[idx(i, j)] % 3;
			if (tri[i][j] == 1)
			{
				Os++;
			}
			else if (tri[i][j] == 2)
			{
				Xs++;
			}
		}
	}
	bool win = false;
	for (int i = 0; i < 3; ++i)
	{
		if (tri[i][0] == tri[i][1] && tri[i][0] == tri[i][2] && tri[i][0] != 0)
		{
			win = true;
			break;
		}
		if (tri[0][i] == tri[1][i] && tri[0][i] == tri[2][i] && tri[0][i] != 0)
		{
			win = true;
			break;
		}
	}
	if (tri[0][0] == tri[1][1] && tri[0][0] == tri[2][2] && tri[0][0] != 0)
	{
		win = true;
	}
	if (tri[2][0] == tri[1][1] && tri[2][0] == tri[0][2] && tri[2][0] != 0)
	{
		win = true;
	}
	if (win)
	{
		return f[tris] = WIN;
	}
	if (Os + Xs == 9)
	{
		return f[tris] = UNKNOWN;
	}
	if (Os == Xs)
	{
		bool existWin = false;
		bool isAllLose = true;
		for (int i = 0; i < 3; ++i)
		{
			for (int j = 0; j < 3; ++j)
			{
				if (tri[i][j] == 0)
				{
					Status rnt = dfs(tris + pow[idx(i, j)]);
					if (rnt == WIN)
					{
						existWin = true;
					}
					else if (rnt == UNKNOWN)
					{
						isAllLose = false;
					}
				}
			}
		}
		if (existWin)
		{
			return f[tris] = LOSE;
		}
		if (isAllLose)
		{
			return f[tris] = WIN;
		}
		return f[tris] = UNKNOWN;
	}
	else if (Os == Xs + 1)
	{
		bool existWin = false;
		bool isAllLose = true;
		for (int i = 0; i < 3; ++i)
		{
			for (int j = 0; j < 3; ++j)
			{
				if (tri[i][j] == 0)
				{
					Status rnt = dfs(tris + pow[idx(i, j)] * 2);
					if (rnt == WIN)
					{
						existWin = true;
					}
					else if (rnt == UNKNOWN)
					{
						isAllLose = false;
					}
				}
			}
		}
		if (existWin)
		{
			return f[tris] = LOSE;
		}
		if (isAllLose)
		{
			return f[tris] = WIN;
		}
		return f[tris] = UNKNOWN;
	}
	else
	{
		return f[tris] = INVALID;
	}
}

bool nowater[19683];

void dfs2(int tris)
{
	if (f[tris] != UNKNOWN || nowater[tris])
	{
		return;
	}
	nowater[tris] = true;
	int tri[3][3];
	int Os = 0;
	int Xs = 0;
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			tri[i][j] = tris / pow[idx(i, j)] % 3;
			if (tri[i][j] == 1)
			{
				Os++;
			}
			else if (tri[i][j] == 2)
			{
				Xs++;
			}
		}
	}
	if (Os == Xs)
	{
		for (int i = 0; i < 3; ++i)
		{
			for (int j = 0; j < 3; ++j)
			{
				if (tri[i][j] == 0)
				{
					dfs2(tris + pow[idx(i, j)]);
				}
			}
		}
	}
	else if (Os == Xs + 1)
	{
		for (int i = 0; i < 3; ++i)
		{
			for (int j = 0; j < 3; ++j)
			{
				if (tri[i][j] == 0)
				{
					dfs2(tris + pow[idx(i, j)] * 2);
				}
			}
		}
	}
}

char s[3][4];

int main()
{
	memset(f, -1, sizeof f);
	memset(nowater, 0, sizeof nowater);
	dfs(0);
	dfs2(0);
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int sum = 0;
		for (int i = 0; i < 3; ++i)
		{
			scanf("%s", s[i]);
			for (int j = 0; j < 3; ++j)
			{
				if (s[i][j] == 'O')
				{
					sum += pow[idx(i, j)];
				}
				else if (s[i][j] == 'X')
				{
					sum += pow[idx(i, j)] * 2;
				}
			}
		}
		if (f[sum] == INVALID)
		{
			printf("INVALID\n");
		}
		else if (nowater[sum])
		{
			printf("REACHABLE\n");
		}
		else
		{
			printf("UNREACHABLE\n");
		}
	}
	return 0;
}
