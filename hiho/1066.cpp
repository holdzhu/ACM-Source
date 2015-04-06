#include <iostream>
#include <map>

using namespace std;

map<string, string> p;

string find(string x)
{
	return x == p[x] ? x : p[x] = find(p[x]);
}

int main()
{
	int N;
	cin >> N;
	while (N--)
	{
		int c;
		string a, b;
		cin >> c >> a >> b;
		if (!p.count(a))
		{
			p[a] = a;
		}
		if (!p.count(b))
		{
			p[b] = b;
		}
		string u = find(p[a]);
		string v = find(p[b]);
		if (c)
		{
			if (u == v)
			{
				cout << "yes\n";
			}
			else
			{
				cout << "no\n";
			}
		}
		else
		{
			p[u] = v;
		}
	}
	return 0;
}
