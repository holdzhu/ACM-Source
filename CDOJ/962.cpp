#include <cstdio>
#include <cstdlib>
#include <cstring>

struct Point
{
	int u, v;
};

int cmp(const void *a, const void *b)
{
	if (((Point *)a)->u > ((Point *)b)->u)
	{
		return -1;
	}
	else if (((Point *)a)->u < ((Point *)b)->u)
	{
		return 1;
	}
	else
	{
		if (((Point *)a)->v > ((Point *)b)->v)
		{
			return -1;
		}
		else if (((Point *)a)->v < ((Point *)b)->v)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
}

int main()
{
	int n;
	scanf("%d", &n);
	Point a[n];
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &a[i].u);
		scanf("%d", &a[i].v);
	}
	Point s1[n];
	memcpy(s1, a, sizeof(a));
	for (int i = 0; i < n; ++i)
	{
		int p = i;
		for (int j = i + 1; j < n; ++j)
		{
			if (s1[j].u < s1[p].u || (s1[j].u == s1[p].u && s1[j].v < s1[p].v))
			{
				p = j;
			}
		}
		if (p > i)
		{
			Point t;
			t.u = s1[p].u;
			t.v = s1[p].v;
			s1[p].u = s1[i].u;
			s1[p].v = s1[i].v;
			s1[i].u = t.u;
			s1[i].v = t.v;
		}
	}
	for (int i = 0; i < n; ++i)
	{
		printf("(%d,%d) ", s1[i].u, s1[i].v);
	}
	printf("\n");
	qsort(a, n, sizeof(Point), cmp);
	for (int i = 0; i < n; ++i)
	{
		printf("(%d,%d) ", a[i].u, a[i].v);
	}
	printf("\n");
	return 0;
}
