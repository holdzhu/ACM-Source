// BEGIN CUT HERE
/*

*/
// END CUT HERE
#line 7 "TheEmpireStrikesBack.cpp"
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
using namespace std;

#define PB push_back
#define MP make_pair

#define REP(i,n) for(i=0;i<(n);++i)
#define FOR(i,l,h) for(i=(l);i<=(h);++i)
#define FORD(i,h,l) for(i=(h);i>=(l);--i)

typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<double> VD;
typedef long long LL;
typedef pair<int,int> PII;

const int mod = 1e9 + 7;

class TheEmpireStrikesBack
{
	public:
	int find(int AX, int BX, int CX, int AY, int BY, int CY, int N, int M)
	{
		vector<pair<int, int> > p(N);
		p[0].first = AX;
		p[0].second = AY;
		for (int i = 1; i < N; ++i)
		{
			p[i].first = (1ll * p[i - 1].first * BX + CX) % mod;
			p[i].second = (1ll * p[i - 1].second * BY + CY) % mod;
		}
		vector<pair<int, int> > ch;
		sort(p.begin(), p.end());
		ch.push_back(p[0]);
		for (int i = 1; i < N; ++i)
		{
			if (p[i].first == ch.back().first)
			{
				ch.back() = p[i];
			}
			else
			{
				while (ch.size() && ch.back().second < p[i].second)
				{
					ch.pop_back();
				}
				ch.push_back(p[i]);
			}
		}
		int L = 0;
		int R = mod + 10;
		vector<int> dp(ch.size());
		while (L < R)
		{
			int T = (L + R) >> 1;
			int l = 0, r = 0, j = 0;
			for (int i = 0; i < ch.size(); ++i)
			{
				while (l < ch.size() && !(ch[i].first + T >= ch[l].first && ch[i].second + T >= ch[l].second))
					l++;
				while (r < ch.size() && ch[i].first + T >= ch[r].first && ch[i].second + T >= ch[r].second)
					r++;
				int mi = l == 0 ? 0 : dp[l - 1];
				for (; j < r; ++j)
					dp[j] = mi + 1;
			}
			if (dp[ch.size() - 1] <= M)
				R = T;
			else
				L = T + 1;
		}
		return L;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arg1 = 2; int Arg2 = 2; int Arg3 = 2; int Arg4 = 2; int Arg5 = 2; int Arg6 = 2; int Arg7 = 1; int Arg8 = 0; verify_case(0, Arg8, find(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7)); }
	void test_case_1() { int Arg0 = 2; int Arg1 = 2; int Arg2 = 2; int Arg3 = 2; int Arg4 = 4; int Arg5 = 1000000000; int Arg6 = 2; int Arg7 = 1; int Arg8 = 1; verify_case(1, Arg8, find(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7)); }
	void test_case_2() { int Arg0 = 1; int Arg1 = 3; int Arg2 = 8; int Arg3 = 10000; int Arg4 = 10; int Arg5 = 999910000; int Arg6 = 3; int Arg7 = 1; int Arg8 = 30; verify_case(2, Arg8, find(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7)); }
	void test_case_3() { int Arg0 = 0; int Arg1 = 0; int Arg2 = 0; int Arg3 = 0; int Arg4 = 0; int Arg5 = 0; int Arg6 = 100000; int Arg7 = 1000; int Arg8 = 0; verify_case(3, Arg8, find(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7)); }
	void test_case_4() { int Arg0 = 10; int Arg1 = 20; int Arg2 = 30; int Arg3 = 40; int Arg4 = 50; int Arg5 = 60; int Arg6 = 100000; int Arg7 = 10; int Arg8 = 15720; verify_case(4, Arg8, find(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
	TheEmpireStrikesBack ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
