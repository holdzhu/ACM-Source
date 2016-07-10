#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

map<string, vector<string> > mp;
map<vector<string>, vector<string> > ans;

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		string s;
		cin >> s;
		s = s.substr(7) + '/';
		int pos = s.find_first_of('/');
		mp[s.substr(0, pos)].push_back(s.substr(pos));
	}
	for (auto &p: mp)
	{
		sort(p.second.begin(), p.second.end());
		p.second.erase(unique(p.second.begin(), p.second.end()), p.second.end());
		ans[p.second].push_back(p.first);
	}
	int cnt = 0;
	for (auto &p: ans)
		if (p.second.size() > 1)
			cnt++;
	cout << cnt << '\n';
	for (auto &p: ans)
		if (p.second.size() > 1)
		{
			for (string &s: p.second)
				cout << "http://" << s << ' ';
			cout << '\n';
		}
	return 0;
}
