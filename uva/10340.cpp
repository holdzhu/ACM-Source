#include <iostream>

using namespace std;

int main()
{
	string s, t;
	while (cin >> s >> t)
	{
		int p = 0;
		bool b = true;
		for (int i = 0; i < s.length(); ++i)
		{
			while (t[p] != s[i] && p < t.length())
			{
				p++;
			}
			if (p == t.length())
			{
				b = false;
				break;
			}
			p++;
		}
		cout << (b ? "Yes" : "No") << "\n";
	}
	return 0;
}
