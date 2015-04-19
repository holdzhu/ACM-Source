#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

struct Word
{
	string w;
	int c;
	bool operator < (const Word& rhs) const
	{
		return w < rhs.w;
	}
};

Word words[150];

inline long long ceil(long long a, long long b)
{
	if (a % b == 0)
	{
		return a / b;
	}
	return a / b + 1;
}

int main()
{
	int W, N;
	int cloud = 1;
	while (scanf("%d %d", &W, &N) == 2 && W && N)
	{
		int cmax = 0;
		for (int i = 0; i < N; ++i)
		{
			cin >> words[i].w >> words[i].c;
			if (words[i].c > cmax)
			{
				cmax = words[i].c;
			}
		}
		sort(words, words + N);
		long long w = 0;
		long long h = 0;
		long long maxh = 0;
		for (int i = 0; i < N; ++i)
		{
			long long height = 8 + ceil(40 * (words[i].c - 4), cmax - 4);
			long long width = ceil(9 * words[i].w.length() * height, 16);
			if (w == 0)
			{
				w = width;
				maxh = height;
			}
			else
			{
				if (w + 10 + width <= W)
				{
					w += 10 + width;
					maxh = max(maxh, height);
				}
				else
				{
					w = width;
					h += maxh;
					maxh = height;
				}
			}
		}
		printf("CLOUD %d: %lld\n", cloud++, h + maxh);
	}
	return 0;
}
