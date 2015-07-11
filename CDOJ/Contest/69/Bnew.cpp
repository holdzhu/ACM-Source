#include <cstdio>
#include <algorithm>

using namespace std;

struct Girl
{
	double s, r;
};

Girl girl[200000];
int p[200000];
int shell[200000];
int all[200000];
int num = 0;
int total = 0;

bool cmp(const int& a, const int& b)
{
	return girl[a].s < girl[b].s || (girl[a].s == girl[b].s && girl[a].r > girl[b].r);
}

Girl operator - (const Girl& a, const Girl& b)
{
	return (Girl){a.s - b.s, a.r - b.r};
}

double cross(const Girl& a, const Girl& b)
{
	return a.s * b.r - a.r * b.s;
}

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%lf %lf", &girl[i].s, &girl[i].r);
		girl[i].s = 1 / girl[i].s;
		girl[i].r = 1 / girl[i].r;
		p[i] = i;
	}
	sort(p, p + n, cmp);
	for (int i = 0; i < n; ++i)
	{
		if (!(num > 0 && ((girl[p[i]].s > girl[shell[num - 1]].s && girl[p[i]].r >= girl[shell[num - 1]].r) ||
							(girl[p[i]].s >= girl[shell[num - 1]].s && girl[p[i]].r > girl[shell[num - 1]].r))))
		{
			if (!(num > 0 && girl[p[i]].s == girl[shell[num - 1]].s && girl[p[i]].r == girl[shell[num - 1]].r))
			{
				while ((num > 0 && girl[p[i]].s <= girl[shell[num - 1]].s && girl[p[i]].r <= girl[shell[num - 1]].r) ||
					(num > 1 && cross(girl[shell[num - 1]] - girl[shell[num - 2]], girl[p[i]] - girl[shell[num - 2]]) <= 0))
				{
					while (total > 0 && girl[all[total - 1]].s == girl[shell[num - 1]].s && girl[all[total - 1]].r == girl[shell[num - 1]].r)
					{
						total--;
					}
					num--;
				}
				shell[num++] = p[i];
			}
			all[total++] = p[i];
		}
	}
	sort(all, all + total);
	for (int i = 0; i < total; ++i)
	{
		if (i)
		{
			printf(" ");
		}
		printf("%d", all[i] + 1);
	}
	printf("\n");
	return 0;
}
