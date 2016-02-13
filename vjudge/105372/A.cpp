#include <cstdio>

const int mo[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const int me[] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int _d, _m, _y;

bool readDate(int &x)
{
	int d, m, y;
	if (scanf("%d/%d/%d", &d, &m, &y) != 3)
		return false;
	_d = d;
	_m = m;
	_y = y;
	x = 365 * y + (y + 3) / 4;
	auto M = y % 4 == 0 ? me : mo;
	for (int i = 0; i < m - 1; ++i)
		x += M[i];
	x += d;
	return true;
}

char s[1000000];

int main()
{
	int T;
	scanf("%d", &T);
	int cnt = 0;
	int tar;
	while (1)
	{
		int x;
		if (!readDate(x))
			break;
		gets(s);
		int first = 0;
		for ( ; s[first] == ' '; ++first);
		int last = 0;
		for ( ; s[last]; ++last);
		if (first == last)
		{
			puts("");
			printf("Current date %02d/%02d/%02d\n", _d, _m, _y);
			cnt = 0;
			tar = x;
		}
		else
		{
			s[last - 2] = 0;
			if (s[last - 1] == 'A' && tar - x >= 180)
			{
				printf("Accepted %s %d\n", s + first, ++cnt);
			}
			else
			{
				printf("Denied %s\n", s + first);
			}
		}
	}
	return 0;
}
