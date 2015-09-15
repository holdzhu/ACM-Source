// BEGIN CUT HERE
/*

*/
// END CUT HERE
#line 7 "BearAttacks.cpp"
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


class BearAttacks
{
	public:
	int expectedValue(int N, int R0, int A, int B, int M, int LOW, int HIGH)
	{
		return int();
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; int Arg1 = 0; int Arg2 = 2; int Arg3 = 3; int Arg4 = 100; int Arg5 = 938593850; int Arg6 = 1000000000; int Arg7 = 21; verify_case(0, Arg7, expectedValue(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6)); }
	void test_case_1() { int Arg0 = 3; int Arg1 = 0; int Arg2 = 0; int Arg3 = 0; int Arg4 = 1; int Arg5 = 0; int Arg6 = 0; int Arg7 = 23; verify_case(1, Arg7, expectedValue(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6)); }
	void test_case_2() { int Arg0 = 6; int Arg1 = 303840291; int Arg2 = 848660283; int Arg3 = 395739574; int Arg4 = 950123456; int Arg5 = 0; int Arg6 = 1000000000; int Arg7 = 3856; verify_case(2, Arg7, expectedValue(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6)); }
	void test_case_3() { int Arg0 = 1; int Arg1 = 0; int Arg2 = 0; int Arg3 = 0; int Arg4 = 1; int Arg5 = 0; int Arg6 = 0; int Arg7 = 1; verify_case(3, Arg7, expectedValue(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6)); }
	void test_case_4() { int Arg0 = 19; int Arg1 = 384038999; int Arg2 = 938592393; int Arg3 = 692854433; int Arg4 = 1000000000; int Arg5 = 300000000; int Arg6 = 600000000; int Arg7 = 473263988; verify_case(4, Arg7, expectedValue(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
	BearAttacks ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
