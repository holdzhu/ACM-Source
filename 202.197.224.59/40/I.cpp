#include <cstdio>
#include <cstring>

const int maxn = 150;

int v[16591750];
int p[100002];
int w[100002];

inline int min(int i, int j)
{
	return i < j ? i : j;
}

int get(int i, int j)
{
	if (i == 0 && j == 0)
	{
		return 1;
	}
	if (j == 0)
	{
		return 0;
	}
	if (i == 0)
	{
		return 0;
	}
	if (j > w[i])
	{
		return 0;
	}
	if (p[i] + j <= p[i + 1])
	{
		return v[p[i] + j - 1];
	}
	return get(i - j, j) + get(i - j, j - 1);
}

void init()
{
	int pos = 1;
	int width = 1;
	int sum = 0;
	while (pos <= 100001)
	{
		for (int i = 0; i < width + 1; ++i)
		{
			if (pos + i <= 100001)
			{
				p[pos + i] = sum;
				w[pos + i] = width;
				sum += min(maxn, width);
			}
		}
		pos += width + 1;
		width++;
	}
	printf("%d\n", sum);
}

int main()
{
	init();
	int T;
	scanf("%d", &T);
	for (int i = 1; i <= 100000; ++i)
	{
		v[p[i]] = 1;
		for (int j = 2; j <= min(p[i + 1] - p[i], maxn); ++j)
		{
			v[p[i] + j - 1] = get(i - j, j) + get(i - j, j - 1);
		}
	}
	while (T--)
	{
		int n, m;
		scanf("%d %d", &n, &m);
		printf("%d\n", get(n, m));
	}
	return 0;
}
