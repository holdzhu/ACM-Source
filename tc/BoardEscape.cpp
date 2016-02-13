// BEGIN CUT HERE
/*

*/
// END CUT HERE
#line 7 "BoardEscape.cpp"
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


class BoardEscape
{
	public:
	string findWinner(vector <string> s, int k)
	{
		int r = s.size();
		int c = s[0].size();
		auto isValid = [r, c](int x, int y){return x >= 0 && y >= 0 && x < r && y < c; };
		static const int dx[] = {0, 0, 1, -1};
		static const int dy[] = {1, -1, 0, 0};
		k %= 2;
		int cnt1 = 0;
		int cnt2 = 0;
		int ans = 0;
		for (int i = 0; i < r; ++i)
		{
			for (int j = 0; j < c; ++j)
			{
				if (s[i][j] == 'T')
				{
					int Ecnt = 0, Ocnt = 0;
					for (int k = 0; k < 4; ++k)
					{
						int x = i + dx[k];
						int y = j + dy[k];
						if (isValid(x, y))
						{
							if (s[x][y] == 'E') Ecnt++;
							if (s[x][y] == '#') Ocnt++;
						}
					}
					if (Ocnt == 4)
					{

					}
					else if (Ecnt + Ocnt == 4)
					{
						ans++;
					}
					else if (Ecnt > 0)
					{
						cnt2++;
					}
					else
					{
						cnt1++;
					}
				}
			}
		}
		ans += k * cnt1;
		if (cnt2 == 0 || k == 1)
		{
			ans += k * cnt2;
			return ans % 2 == 0 ? "Bob" : "Alice";
		}
		return cnt2 % 2 == 0 ? "Bob" : "Alice";
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"TE"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; string Arg2 = "Alice"; verify_case(0, Arg2, findWinner(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"E#E",
 "#T#",
 "E#E"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1000000; string Arg2 = "Bob"; verify_case(1, Arg2, findWinner(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"T.T.T.",
 ".E.E.E"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; string Arg2 = "Alice"; verify_case(2, Arg2, findWinner(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"TTE"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 6; string Arg2 = "Alice"; verify_case(3, Arg2, findWinner(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = {"..........................",
 "......TTT..TTT..T...T.....",
 ".....T.....T..T.TT.TT.....",
 "......TTT..TTT..T.T.T.....",
 ".........T.T.T..T...T.....",
 "......TTT..T..T.T...T.....",
 "..........................",
 "...E#E#E#E#E#E#E#E#E#E#...",
 "..........................",
 "......TTT..TTT...TTT......",
 ".....T........T.T.........",
 "......TTT.....T..TTT......",
 ".....T...T...T..T...T.....",
 "......TTT....T...TTT......",
 "..........................",
 "...#E#E#E#E#E#E#E#E#E#E...",
 "..........................",
 "....TT...T...T..T.TTT.T...",
 "...T.....T...T..T.T...T...",
 "...T.TT..T...TTTT.TT..T...",
 "...T..T..T...T..T.T.......",
 "....TT...TTT.T..T.T...T...",
 ".........................."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 987654321; string Arg2 = "Bob"; verify_case(4, Arg2, findWinner(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
	BoardEscape ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
