#include <cstdio>

struct Girl
{
	int s, r;
};

Girl girl[200000];

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d %d", &girl[i].s, &girl[i].r);
	}
	bool first = true;
	for (int i = 0; i < n; ++i)
	{
		bool flag = true;
		for (int j = 0; j < n; ++j)
		{
			if ((girl[i].s < girl[j].s && girl[i].r <= girl[j].r) || (girl[i].s <= girl[j].s && girl[i].r < girl[j].r))
			{
				flag = false;
				break;
			}
		}
		if (flag)
		{
			if (first)
			{
				first = false;
			}
			else
			{
				printf(" ");
			}
			printf("%d", i + 1);
		}
	}
	printf("\n");
	return 0;
}
