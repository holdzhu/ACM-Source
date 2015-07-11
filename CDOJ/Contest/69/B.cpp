#include <cstdio>
#include <algorithm>

using namespace std;

struct Girl
{
	int s, r;
};

Girl girl[200000];
int p[200000];
int desc[200000];
int shell[200000];
int descnum = 0;
int shellnum = 0;

bool cmp(const int& a, const int& b)
{
	return girl[a].s < girl[b].s || (girl[a].s == girl[b].s && girl[a].r < girl[b].r);
}

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d %d", &girl[i].s, &girl[i].r);
		p[i] = i;
	}
	sort(p, p + n, cmp);
	for (int i = 0; i < n; ++i)
	{
		while (descnum > 0 && 
			((girl[desc[descnum - 1]].s < girl[p[i]].s && girl[desc[descnum - 1]].r <= girl[p[i]].r) || 
			(girl[desc[descnum - 1]].s <= girl[p[i]].s && girl[desc[descnum - 1]].r < girl[p[i]].r)))
		{
			descnum--;
		}
		desc[descnum++] = p[i];
	}
	for (int i = 0; i < descnum; ++i)
	{
		while (shellnum > 0 && 
			((girl[desc[shellnum - 1]].s < girl[p[i]].s && girl[desc[shellnum - 1]].r <= girl[p[i]].r) || 
			(girl[desc[shellnum - 1]].s <= girl[p[i]].s && girl[desc[shellnum - 1]].r < girl[p[i]].r)))
		{
			shellnum--;
		}
		desc[shellnum++] = p[i];
	}
	sort(shell, shell + shellnum);
	for (int i = 0; i < shellnum; ++i)
	{
		if (i)
		{
			printf(" ");
		}
		printf("%d", shell[i] + 1);
	}
	printf("\n");
	return 0;
}
