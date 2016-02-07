#include <cstdio>
#include <stack>

using namespace std;

char match[128];
char s[1000001];

int main()
{
	match[']'] = '[';
	match['>'] = '<';
	match[')'] = '(';
	match['}'] = '{';
	scanf("%s", s);
	bool flag = true;
	int ans = 0;
	stack<char> stk;
	for (int i = 0; s[i]; ++i)
	{
		if (match[s[i]])
		{
			if (stk.empty())
			{
				flag = false;
				break;
			}
			ans += stk.top() != match[s[i]];
			stk.pop();
		}
		else
		{
			stk.push(s[i]);
		}
	}
	if (stk.size() || flag == false)
	{
		puts("Impossible");
	}
	else
	{
		printf("%d\n", ans);
	}
	return 0;
}
