#include <cstdio>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

map<string, string> ms;

int main()
{
	int n;
	while (scanf("%d", &n) == 1 && n)
	{
		set<string> ss;
		string fs;
		ms.clear();
		for (int i = 0; i < n; ++i)
		{
			char ts[10000];
			scanf("%s", ts);
			char * p = strtok(ts, ":");
			string t = p;
			if (i == 0)
			{
				fs = p;
			}
			while ((p = strtok(NULL, ",.")) != NULL)
			{
				if (!ms.count(p))
				{
					ms.insert(make_pair(p, t));
				}
			}
		}
		
	}
	return 0;
}
