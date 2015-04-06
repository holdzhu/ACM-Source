#include <cstdio>
#include <set>

using namespace std;

struct cmd
{
	char c;
	int d;
};

int main()
{
	int w, h, n;
	scanf("%d %d %d", &w, &h, &n);
	cmd cm[n];
	set<int> wc, hc;
	wc.insert(0);
	wc.insert(w);
	hc.insert(0);
	hc.insert(h);
	for (int i = 0; i < n; ++i)
	{
		scanf(" %c %d", &cm[i].c, &cm[i].d);
		if (cm[i].c == 'H')
		{
			hc.insert(cm[i].d);
		}
		else
		{
			wc.insert(cm[i].d);
		}
	}
	int maxdw = 0;
	int maxdh = 0;
	int lw = 0;
	int lh = 0;
	for (set<int>::iterator i = wc.begin(); i != wc.end(); ++i)
	{
		if (*i - lw > maxdw)
		{
			maxdw = *i - lw;
		}
		lw = *i;
	}
	for (set<int>::iterator i = hc.begin(); i != hc.end(); ++i)
	{
		if (*i - lh > maxdh)
		{
			maxdh = *i - lh;
		}
		lh = *i;
	}
	long long ans[n];
	for (int i = n - 1; i >= 0; --i)
	{
		ans[i] = (long long)maxdh * maxdw;
		if (cm[i].c == 'V')
		{
			set<int>::iterator si = wc.find(cm[i].d);
			int l = *(--si);
			++si;
			int r = *(++si);
			--si;
			if (r - l > maxdw)
			{
				maxdw = r - l;
			}
			wc.erase(si);
		}
		else
		{
			set<int>::iterator si = hc.find(cm[i].d);
			int l = *(--si);
			++si;
			int r = *(++si);
			--si;
			if (r - l > maxdh)
			{
				maxdh = r - l;
			}
			hc.erase(si);
		}
	}
	for (int i = 0; i < n; ++i)
	{
		printf("%I64d\n", ans[i]);
	}
	return 0;
}
