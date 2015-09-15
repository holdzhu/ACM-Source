#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

bool vis[1000001];
bool vistmp[1000001];
vector<int> s;

int main()
{
	int N, M;
	scanf("%d %d", &N, &M);
	memset(vis, false, sizeof vis);
	for (int i = 0; i <= M; ++i)
	{
		for (int j = i; j <= M; ++j)
		{
			int t = i * i + j * j;
			if (!vis[t])
			{
				s.push_back(t);
				vis[t] = true;
			}
		}
	}
	sort(s.begin(), s.end());
	int maxn = M * M * 2;
	int maxb = maxn / (N - 1);
	bool flag = false;
	memset(vistmp, false, sizeof vistmp);
	for (int b = 1; b <= maxb; ++b)
	{
		vector<int> tmp;
		for (int j = 0; j < s.size() && s[j] + b * (N - 1) <= maxn; ++j)
		{
			if (vistmp[s[j]])
			{
				continue;
			}
			int cnt = 1;
			while (1)
			{
				if (!vis[s[j] + b * cnt])
				{
					break;
				}
				cnt++;
			}
			if (cnt >= N)
			{
				flag = true;
				for (int k = 0; k < cnt - N + 1; ++k)
				{
					tmp.push_back(s[j] + b * k);
					vistmp[s[j] + b * k] = true;
				}
			}
		}
		sort(tmp.begin(), tmp.end());
		for (int i = 0; i < tmp.size(); ++i)
		{
			printf("%d %d\n", tmp[i], b);
			vistmp[tmp[i]] = false;
		}
	}
	if (!flag)
	{
		printf("NONE\n");
	}
	return 0;
}
