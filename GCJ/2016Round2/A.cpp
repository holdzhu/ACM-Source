#include <cstdio>
#include <algorithm>
#include <string>

using namespace std;

const char order[] = "RSP";

string solve(int n, int cur)
{
	if (n == 0)
		return string() + order[cur];
	string s1 = solve(n - 1, cur);
	string s2 = solve(n - 1, (cur + 1) % 3);
	if (s1 > s2)
		swap(s1, s2);
	return s1 + s2;
}

int main()
{
	int T;
	scanf("%d", &T);
	for (int kase = 1; kase <= T; ++kase)
	{
		int N, R, P, S;
		scanf("%d %d %d %d", &N, &R, &P, &S);
		printf("Case #%d: ", kase);
		int c[3] = {0, 0, 0};
		for (int i = 0; i < (1 << N); ++i)
			++c[__builtin_popcount(i) % 3];
		bool flag = false;
		string ans;
		if (R == c[0] && S == c[1] && P == c[2])
		{
			string t = solve(N, 0);
			if (!flag)
				ans = t;
			else
				ans = min(ans, t);
			flag = true;
		}
		if (S == c[0] && P == c[1] && R == c[2])
		{
			string t = solve(N, 1);
			if (!flag)
				ans = t;
			else
				ans = min(ans, t);
			flag = true;
		}
		if (P == c[0] && R == c[1] && S == c[2])
		{
			string t = solve(N, 2);
			if (!flag)
				ans = t;
			else
				ans = min(ans, t);
			flag = true;
		}
		if (flag)
		{
			printf("%s\n", ans.c_str());
		}
		else
			puts("IMPOSSIBLE");
	}
	return 0;
}
