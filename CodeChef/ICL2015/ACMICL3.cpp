#include <iostream>
#include <map>

using namespace std;

int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int n;
		cin >> n;
		map<string, int> s;
		for (int i = 0; i < n; ++i)
		{
			string t;
			cin >> t;
			s[t]++;
		}
		int c = 0;
		for (map<string, int>::iterator i = s.begin(); i != s.end(); ++i)
		{
			if (i->second % 2)
			{
				c++;
			}
		}
		cout << c << "\n";
	}
	return 0;
}
