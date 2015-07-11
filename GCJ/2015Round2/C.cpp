#include <cstdio>
#include <cstring>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>

using namespace std;

long long encode(char* s)
{
	long long rnt = 0;
	for (int i = 0; s[i]; ++i)
	{
		rnt *= 26;
		rnt += s[i] - 'a';
	}
	return rnt;
}

set<long long> statusA[1 << 18];
set<long long> statusB[1 << 18];
set<long long> word[200];
char buf[20000];
char s[11];

int main()
{
	int T;
	scanf("%d", &T);
	for (int kase = 0; kase < T; ++kase)
	{
		int N;
		scanf("%d ", &N);
		for (int i = 0; i < N; ++i)
		{
			word[i].clear();
			gets(buf);
			char* tmp = strtok(buf, " ");
			while (tmp)
			{
				word[i].insert(encode(tmp));
				tmp = strtok(NULL, " ");
			}
		}
		int ans = 1000000;
		statusA[0] = word[0];
		statusB[0] = word[1];
		for (int i = 1; i < (1 << (N - 2)); ++i)
		{
			int p = 0;
			while (!(i & (1 << p)))
			{
				p++;
			}
			statusA[i] = statusA[i ^ (1 << p)];
			statusA[i].insert(word[p + 2].begin(), word[p + 2].end());
			statusB[i] = statusB[i ^ (1 << p)];
			statusB[i].insert(word[p + 2].begin(), word[p + 2].end());
		}
		int MM = (1 << (N - 2)) - 1;
		for (int i = 0; i < (1 << (N - 2)); ++i)
		{
			vector<long long> res;
			set_intersection(statusA[i].begin(), statusA[i].end(), statusB[MM - i].begin(), statusB[MM - i].end(), inserter(res, res.begin()));
			ans = min(ans, (int)res.size());
		}
		printf("Case #%d: %d\n", kase + 1, ans);
	}
	return 0;
}
