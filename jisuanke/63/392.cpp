#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

char s[51];

bool cmp(const vector<int>& A, const vector<int>& B)
{
	for (int i = 0; i < A.size(); ++i)
	{
		if (A[i] != B[i])
		{
			return A[i] < B[i];
		}
	}
	return false;
}

int main()
{
	scanf("%s", s);
	int l = strlen(s);
	int maxn;
	if (l < 10)
	{
		maxn = l;
	}
	else
	{
		maxn = l / 2 + 5;
	}
	vector<vector<int> > a, b, c;
	b.push_back(vector<int>());
	for (int i = 0; i < l; ++i)
	{
		int d = s[i] - '0';
		if (d != 0 && d <= maxn)
		{
			for (int j = 0; j < b.size(); ++j)
			{
				bool flag = true;
				for (int k = 0; k < b[j].size(); ++k)
				{
					if (b[j][k] == d)
					{
						flag = false;
						break;
					}
				}
				if (flag)
				{
					c.push_back(b[j]);
					c[c.size() - 1].push_back(d);
				}
			}
		}
		if (i && s[i - 1] <= '3' && s[i - 1] != '0')
		{
			d = d + (s[i - 1] - '0') * 10;
			if (d <= maxn)
			{
				for (int j = 0; j < a.size(); ++j)
				{
					bool flag = true;
					for (int k = 0; k < a[j].size(); ++k)
					{
						if (a[j][k] == d)
						{
							flag = false;
							break;
						}
					}
					if (flag)
					{
						c.push_back(a[j]);
						c[c.size() - 1].push_back(d);
					}
				}
			}
		}
		a = b;
		b = c;
		c.clear();
	}
	sort(b.begin(), b.end(), cmp);
	for (int i = 0; i < b[0].size(); ++i)
	{
		if (i)
		{
			printf(" ");
		}
		printf("%d", b[0][i]);
	}
	printf("\n");
	return 0;
}
