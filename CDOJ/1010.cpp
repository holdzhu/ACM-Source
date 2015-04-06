#include <cstdio>
#include <map>

using namespace std;

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int n, k;
		scanf("%d %d", &n, &k);
		map<int, int> m;
		for (int i = 0; i < n; ++i)
		{
			int t;
			scanf("%d", &t);
			if (m.count(t))
			{
				m[t]++;
			}
			else
			{
				m[t] = 1;
			}
		}
		bool flag = true;
		for (map<int, int>::iterator i = m.begin(); i != m.end(); ++i)
		{
			if (i->second == k)
			{
				flag = false;
				break;
			}
		}
		if (flag)
		{
			printf("No\n");
		}
		else
		{
			printf("Yes\n");
		}
	}
	return 0;
}
