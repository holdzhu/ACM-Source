#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <set>
#include <algorithm>

using namespace std;

char s[100001];

int main()
{
	int T;
	scanf("%d", &T);
	for (int kase = 1; kase <= T; ++kase)
	{
		scanf("%s", s);
		printf("Case #%d: ", kase);
		int l = strlen(s);
		int sq = sqrt(l + 0.5);
		bool success = false;
		for (int num = sq; num >= 1; --num)
		{
			if (l % (num * num) == 0)
			{
				int len = l / num;
				int k = len / num;
				if (k >= 2)
				{
					string t = "";
					for (int i = 0; i < num; ++i)
					{
						t += s[i];
					}
					bool flag = true;
					for (int i = 1; i < k; ++i)
					{
						for (int j = 0; j < num; ++j)
						{
							if (t[j] != s[num * i + j])
							{
								flag = false;
								break;
							}
						}
					}
					if (!flag)
					{
						continue;
					}
				}
				set<string> m;
				for (int i = 0; i < num; ++i)
				{
					string t = "";
					for (int j = i; j < len; ++j)
					{
						t += s[j];
					}
					for (int j = 0; j < i; ++j)
					{
						t += s[j];
					}
					m.insert(t);
				}
				string ans = *m.begin();
				bool flag = true;
				for (int i = 0; i < num; ++i)
				{
					string t = "";
					for (int j = 0; j < len; ++j)
					{
						t += s[i * len + j];
					}
					if (!m.count(t))
					{
						flag = false;
						break;
					}
					m.erase(t);
				}
				if (flag && m.size() == 0)
				{
					cout << ans << "\n";
					success = true;
					break;
				}
			}
		}
		if (!success)
		{
			printf("Impossible\n");
		}
	}
	return 0;
}