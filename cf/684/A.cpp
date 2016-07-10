#include <cstdio>
#include <algorithm>

using namespace std;

const int n = 5000;
const int k = 2000;
const int x = 100;

bool b[n];
bool nb[n];
int p[n];

void output()
{
	for (int i = 0; i < n; ++i)
		putchar('0' + b[i]);
	puts("");
	fflush(stdout);
	static int _ = x;
	if (--_ == 0)
		exit(0);
}

int main()
{
	srand(23333);
	for (int i = 0; i < n; ++i)
		b[i] = rand() & 1;
	output();
	while (1)
	{
		int t;
		scanf("%d", &t);
	after:
		if (t - k < k)
		{
			for (int i = 0; i < n; ++i)
				b[i] ^= 1;
			output();
		}
		else while (1)
		{
			for (int i = 0; i < t; ++i)
				nb[i] = b[i];
			for (int i = 0; i < t; ++i)
				p[i] = i;
			random_shuffle(p, p + 75);
			for (int i = 0; i < k; ++i)
				b[p[i]] ^= 1;
			output();
			int t2;
			scanf("%d", &t2);
			if (t2 > t)
			{
				t = t2;
				goto after;
			}
			for (int i = 0; i < t; ++i)
				b[i] = nb[i];
		}
	}
	return 0;
}
