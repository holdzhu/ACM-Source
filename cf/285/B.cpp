#include <iostream>
#include <map>
using namespace std;

int main()
{
	int q;
	cin >> q;
	map<string, string> m;
	string sold;
	string snew;
	while (q--)
	{
		cin >> sold >> snew;
		if (m.count(sold))
		{
			string t = m[sold];
			m.erase(sold);
			m[snew] = t;
		}
		else
		{
			m[snew] = sold;
		}
	}
	cout << m.size() << "\n";
	for (map<string, string>::iterator i = m.begin(); i != m.end(); ++i)
	{
		cout << i->second << " " << i->first << "\n";
	}
	return 0;
}
