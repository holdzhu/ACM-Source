#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

const int m[] = {1, 0, 0, 1, -1, 0, 0, -1};
const int p[] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320};
int d[362880];

int cantor(int * n)
{
	int rnt = 0;
	for (int i = 0; i < 9; ++i)
	{
		int num = 0;
		for (int j = i + 1; j < 9; ++j)
		{
			if (n[i] > n[j])
			{
				num++;
			}
		}
		rnt += num * p[8 - i];
	}
	return rnt;
}

int main()
{
	memset(d, -1, sizeof d);
	queue<int> q;
	d[0] = 0;
	q.push(0);
	int n[9];
	bool h[9];
	while (!q.empty())
	{
		int t = q.front();
		int _t = t;
		q.pop();
		memset(h, 0, sizeof(h));
		int x;
		for (int i = 0; i < 9; ++i)
		{
			n[i] = _t / p[8 - i];
			_t %= p[8 - i];
			for (int j = 0; j < 9; ++j)
			{
				if (!h[j] && --n[i] < 0)
				{
					h[n[i] = j] = true;
					break;
				}
			}
			if (n[i] == 8)
			{
				x = i;
			}
		}
		for (int i = 0; i < 4; ++i)
		{
			int dx = x / 3 + m[i * 2];
			int dy = x % 3 + m[i * 2 + 1];
			if (dx >= 0 && dy >= 0 && dx < 3 && dy < 3)
			{
				n[x] = n[dx * 3 + dy];
				n[dx * 3 + dy] = 8;
				int c = cantor(n);
				n[dx * 3 + dy] = n[x];
				n[x] = 8;
				if (d[c] == -1)
				{
					d[c] = d[t] + 1;
					q.push(c);
				}
			}
		}
	}
	char s[9];
	while (cin >> s[0] >> s[1] >> s[2] >> s[3] >> s[4] >> s[5] >> s[6] >> s[7] >> s[8])
	{
		for (int i = 0; i < 9; ++i)
		{
			if (s[i] == 'x')
			{
				n[i] = 8;
			}
			else
			{
				n[i] = s[i] - '1';
			}
		}
		int c = cantor(n);
		if (d[c] >= 0)
		{
			cout << d[c] << "\n";
		}
		else
		{
			cout << "unsolvable\n";
		}
	}
	return 0;
}
