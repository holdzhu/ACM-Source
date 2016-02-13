#include <cstdio>

const int me[] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const int mo[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool isleap(int x)
{
	return x % 400 == 0 || (x % 100 != 0 && x % 4 == 0);
}

int main()
{
	int M, N, K;
	scanf("%d %d %d", &M, &N, &K);
	int d, m, y;
	scanf("%d.%d.%d", &d, &m, &y);
	int id = y * 12 + m - 1;
	id += 12 * 60;
	int st = 2012 * 12;
	for (int i = 0; i < K; ++i)
	{
		int s = st + i * N;
		int trueid = id + (int)((isleap(id / 12) && d > me[id % 12]) || (!isleap(id / 12) && d > mo[id % 12]));
		if (s <= trueid)
			id += M;
		else
			break;
	}
	if ((isleap(id / 12) && d > me[id % 12]) || (!isleap(id / 12) && d > mo[id % 12]))
		id++, d = 1;
	printf("%02d.%02d.%04d\n", d, id % 12 + 1, id / 12);
	return 0;
}
