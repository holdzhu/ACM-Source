#include <iostream>
#include <stack>

using namespace std;

int main()
{
	string s;
	stack<string> t;
	while (cin >> s)
		t.push(s);
	while (!t.empty())
	{
		cout << t.top();
		t.pop();
		if (!t.empty())
			cout << ' ';
	}
	cout << '\n';
	return 0;
}
