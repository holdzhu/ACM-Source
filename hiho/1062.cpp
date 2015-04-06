#include <iostream>
#include <set>
#include <map>

using namespace std;

map<string, string> p;
int pos = 0;

int main()
{
	int n, m;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		string u, v;
		cin >> u >> v;
		p[v] = u;
	}
	cin >> m;
	for (int i = 0; i < m; ++i)
	{
		string u1, u2;
		cin >> u1 >> u2;
		string flag = "-1";
		set<string> s;
		while (1)
		{
			s.insert(u1);
			if (!p.count(u1))
			{
				break;
			}
			u1 = p[u1];
		}
		while (1)
		{
			if (s.count(u2))
			{
				flag = u2;
				break;
			}
			if (!p.count(u2))
			{
				break;
			}
			u2 = p[u2];
		}
		cout << flag << "\n";
	}
	return 0;
}
