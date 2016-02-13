#include <iostream>
#include <set>

using namespace std;

set<string> st;
string s[10000];

int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
	{
		cin >> s[i];
	}
	for (int j = 0; j < m; ++j)
	{
		string t;
		cin >> t;
		st.insert(t);
	}
	for (int i = 0; i < n; ++i)
	{
		int ans = 0;
	}
	return 0;
}
