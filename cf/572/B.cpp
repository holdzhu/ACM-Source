#include <cstdio>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

vector<pair<int, int> > B, S;
vector<pair<int, int> > nB, nS;

int main()
{
	int n, s;
	scanf("%d %d", &n, &s);
	for (int i = 0; i < n; ++i)
	{
		char s[2];
		int p, v;
		scanf("%s %d %d", s, &p, &v);
		if (s[0] == 'B')
		{
			B.push_back(make_pair(p, v));
		}
		else
		{
			S.push_back(make_pair(p, v));
		}
	}
	sort(B.begin(), B.end(), greater<pair<int, int> >());
	sort(S.begin(), S.end(), greater<pair<int, int> >());
	for (int i = 0; i < B.size(); ++i)
	{
		if (nB.size() == 0)
		{
			nB.push_back(B[i]);
		}
		else
		{
			if (nB.back().first == B[i].first)
			{
				nB.back().second += B[i].second;
			}
			else
			{
				nB.push_back(B[i]);
			}
		}
	}
	for (int i = 0; i < S.size(); ++i)
	{
		if (nS.size() == 0)
		{
			nS.push_back(S[i]);
		}
		else
		{
			if (nS.back().first == S[i].first)
			{
				nS.back().second += S[i].second;
			}
			else
			{
				nS.push_back(S[i]);
			}
		}
	}
	for (int i = max(0u, nS.size() - s); i < nS.size(); ++i)
	{
		printf("S %d %d\n", nS[i].first, nS[i].second);
	}
	for (int i = 0; i < nB.size() && i < s; ++i)
	{
		printf("B %d %d\n", nB[i].first, nB[i].second);
	}
	return 0;
}
