// BEGIN CUT HERE
/*

*/
// END CUT HERE
#line 7 "ABBADiv1.cpp"
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


class ABBADiv1
{
	public:
	string canObtain(string initial, string target)
	{
		if (target.size() < initial.size())
		{
			return "Impossible";
		}
		if (target.size() == initial.size())
		{
			if (target == initial)
			{
				return "Possible";
			}
			return "Impossible";
		}
		for (int i = 0; i <= target.size() - initial.size(); ++i)
		{
			if (target.substr(i, initial.size()) == initial)
			{
				if (target[0] == 'B' || i == 0)
				{
					int lb = 0;
					int rb = 0;
					for (int j = 0; j < i; ++j)
					{
						lb += target[j] == 'B';
					}
					for (int j = i + initial.size(); j < target.size(); ++j)
					{
						rb += target[j] == 'B';
					}
					if (lb == rb)
					{
						return "Possible";
					}
				}
			}
		}
		string rev;
		for (int i = 0; i < initial.size(); ++i)
		{
			rev = rev + initial[initial.size() - i - 1];
		}
		for (int i = 0; i <= target.size() - rev.size(); ++i)
		{
			if (target.substr(i, rev.size()) == rev)
			{
				if (target[0] == 'B' || i == 0)
				{
					int lb = 0;
					int rb = 0;
					for (int j = 0; j < i; ++j)
					{
						lb += target[j] == 'B';
					}
					for (int j = i + initial.size(); j < target.size(); ++j)
					{
						rb += target[j] == 'B';
					}
					if (lb == rb + 1)
					{
						return "Possible";
					}
				}
			}
		}
		return "Impossible";
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "A"; string Arg1 = "BABA"; string Arg2 = "Possible"; verify_case(0, Arg2, canObtain(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "BAAAAABAA"; string Arg1 = "BAABAAAAAB"; string Arg2 = "Possible"; verify_case(1, Arg2, canObtain(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "A"; string Arg1 = "ABBA"; string Arg2 = "Impossible"; verify_case(2, Arg2, canObtain(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "AAABBAABB"; string Arg1 = "BAABAAABAABAABBBAAAAAABBAABBBBBBBABB"; string Arg2 = "Possible"; verify_case(3, Arg2, canObtain(Arg0, Arg1)); }
	void test_case_4() { string Arg0 = "AAABAAABB"; string Arg1 = "BAABAAABAABAABBBAAAAAABBAABBBBBBBABB"; string Arg2 = "Impossible"; verify_case(4, Arg2, canObtain(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
	ABBADiv1 ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
