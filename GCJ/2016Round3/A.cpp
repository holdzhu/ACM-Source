#include <cstdio>
#include <cstring>
#include <stack>

using namespace std;

char S[20001];

int main()
{
	int T;
	scanf("%d", &T);
	for (int kase = 1; kase <= T; ++kase)
	{
		scanf("%s", S);
		stack<char> s;
		int n = strlen(S);
		for (int i = 0; i < n; ++i)
		{
			if (s.size() && S[i] == s.top())
				s.pop();
			else
				s.push(S[i]);
		}
		printf("Case #%d: ", kase);
		printf("%d\n", n * 5 - (s.size() + 1) / 2 * 5);
	}
	return 0;
}
