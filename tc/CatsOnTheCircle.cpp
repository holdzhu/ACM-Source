// BEGIN CUT HERE
/*

*/
// END CUT HERE
#line 7 "CatsOnTheCircle.cpp"
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


class CatsOnTheCircle
{
	public:
	double getProb(int N, int K, int p)
	{
		return double();
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; int Arg1 = 1; int Arg2 = 300000000; double Arg3 = 0.6999999999999985; verify_case(0, Arg3, getProb(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 6; int Arg1 = 2; int Arg2 = 500000000; double Arg3 = 0.2; verify_case(1, Arg3, getProb(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 6; int Arg1 = 5; int Arg2 = 500000000; double Arg3 = 0.2; verify_case(2, Arg3, getProb(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 10; int Arg1 = 2; int Arg2 = 666666666; double Arg3 = 0.00391389439551009; verify_case(3, Arg3, getProb(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 999999999; int Arg1 = 999999996; int Arg2 = 777777777; double Arg3 = 0.05830903870125612; verify_case(4, Arg3, getProb(Arg0, Arg1, Arg2)); }
	void test_case_5() { int Arg0 = 1000000000; int Arg1 = 4; int Arg2 = 300000000; double Arg3 = 0.044981259448371; verify_case(5, Arg3, getProb(Arg0, Arg1, Arg2)); }
	void test_case_6() { int Arg0 = 534428790; int Arg1 = 459947197; int Arg2 = 500000000; double Arg3 = 1.871156682766205E-9; verify_case(6, Arg3, getProb(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
	CatsOnTheCircle ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE