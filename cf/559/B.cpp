#include <iostream>

using namespace std;

string solve(string s)
{
	if (s.size() & 1)
	{
		return s;
	}
	string a = solve(s.substr(0, s.size() / 2));
	string b = solve(s.substr(s.size() / 2));
	if (a < b)
	{
		return a + b;
	}
	else
	{
		return b + a;
	}
}

int main()
{
	string s, t;
	cin >> s >> t;
	cout << (solve(s) == solve(t) ? "YES" : "NO") << endl;
	return 0;
}
