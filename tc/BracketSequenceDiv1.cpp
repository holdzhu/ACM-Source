#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <string>
#include <utility>
#include <vector>
using namespace std;

long long dp[2][1 << 21];

class BracketSequenceDiv1
{
public:
	long long count(string s)
	{
		auto &x = dp[0], &y = dp[1];
		memset(y, 0, sizeof y);
		y[1] = 1;
		for (int i = 0; i < s.length(); ++i)
		{
			swap(x, y);
			memcpy(y, x, sizeof y);
			if (s[i] == '(' || s[i] == '[')
				for (int j = 1; j < 1 << 20; ++j)
					y[j << 1 | (s[i] == '[')] += x[j];
			else
				for (int j = 2; j < 1 << 21; ++j)
					if ((j & 1) == (s[i] == ']'))
						y[j >> 1] += x[j];
		}
		return y[1] - 1;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "()[]"; long long Arg1 = 3LL; verify_case(0, Arg1, count(Arg0)); }
	void test_case_1() { string Arg0 = "())"; long long Arg1 = 2LL; verify_case(1, Arg1, count(Arg0)); }
	void test_case_2() { string Arg0 = "()()"; long long Arg1 = 4LL; verify_case(2, Arg1, count(Arg0)); }
	void test_case_3() { string Arg0 = "([)]"; long long Arg1 = 2LL; verify_case(3, Arg1, count(Arg0)); }
	void test_case_4() { string Arg0 = "(((((((((((((((((((())))))))))))))))))))"; long long Arg1 = 3854LL; verify_case(4, Arg1, count(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
	BracketSequenceDiv1 ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
