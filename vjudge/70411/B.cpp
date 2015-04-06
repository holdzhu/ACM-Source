#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

struct Node
{
	int step;
	char r[101];
};

int main()
{
	int n;
	while (scanf("%d", &n) == 1 && n)
	{
		char a[n][11];
		char b[n][11];
		int al[n];
		int bl[n];
		for (int i = 0; i < n; ++i)
		{
			scanf("%s %s", a[i], b[i]);
			al[i] = strlen(a[i]);
			bl[i] = strlen(b[i]);
		}
		char s[11];
		char t[11];
		scanf("%s %s", s, t);
		int tl = strlen(t);
		queue<Node> q;
		Node f;
		f.step = 0;
		strcpy(f.r, s);
		q.push(f);
		int ans = 0;
		while (!q.empty() && !ans)
		{
			Node p = q.front();
			q.pop();
			int prl = strlen(p.r);
			for (int i = 0; i < n; ++i)
			{
				char te[101];
				int tp = 0;
				for (int j = 0; j < prl; ++j)
				{
					bool flag = false;
					for (int k = 0; ; ++k)
					{
						if (a[i][k] == '\0')
						{
							strcpy(te + tp, b[i]);
							tp += bl[i];
							j += al[i] - 1;
							flag = true;
							break;
						}
						else if (a[i][k] != p.r[j + k])
						{
							break;
						}
					}
					if (!flag)
					{
						te[tp++] = p.r[j];
					}
				}
				te[tp] = '\0';
				if (prl < tp && tp < tl)
				{
					Node ne;
					ne.step = p.step + 1;
					strcpy(ne.r, te);
					q.push(ne);
				}
				else if (tp == tl)
				{
					if (strcmp(t, te) == 0)
					{
						ans = p.step + 1;
						break;
					}
				}
			}
		}
		if (ans)
		{
			printf("%d\n", ans);
		}
		else
		{
			printf("-1\n");
		}
	}
	return 0;
}
