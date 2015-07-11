#include <cstdio>
#include <vector>
#include <set>

using namespace std;

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int n;
		scanf("%d", &n);
		multiset<int> s;
		for (int i = 0; i < n; ++i)
		{
			int t;
			scanf("%d", &t);
			if (t)
			{
				s.insert(t);
			}
		}
		bool flag = true;
		while (s.size() > 0)
		{
			int p = *(--s.end());
			s.erase(--s.end());
			vector<int> t;
			while (s.size() > 0 && p > 0)
			{
				p--;
				t.push_back(*(--s.end()) - 1);
				s.erase(--s.end());
			}
			if (p > 0)
			{
				flag = false;
				break;
			}
			for (int i = 0; i < t.size(); ++i)
			{
				if (t[i])
				{
					s.insert(t[i]);
				}
			}
		}
		if (flag)
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
	return 0;
}
