// BEGIN CUT HERE
/*

*/
// END CUT HERE
#line 7 "Gxor.cpp"
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


class Gxor
{
	public:
	long long countsubs(vector <string> S)
	{
		return long long();
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"1","1","0"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 4LL; verify_case(0, Arg1, countsubs(Arg0)); }
	void test_case_1() { string Arr0[] = {"011001"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 0LL; verify_case(1, Arg1, countsubs(Arg0)); }
	void test_case_2() { string Arr0[] = {"111011"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 1LL; verify_case(2, Arg1, countsubs(Arg0)); }
	void test_case_3() { string Arr0[] = {"110","011","101"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 6LL; verify_case(3, Arg1, countsubs(Arg0)); }
	void test_case_4() { string Arr0[] = {"111110","100000","100101","010101"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 11LL; verify_case(4, Arg1, countsubs(Arg0)); }
	void test_case_5() { string Arr0[] = {"110010000000111110101001001001101010",
"101011011000101001111110010000000001",
"010001101100000010010110000001100010",
"101100011110001011101000100010001111",
"111010000010010101010111001000000100",
"101100001101011101101011011001000010",
"111111010000000000110000010101100100"}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 121LL; verify_case(5, Arg1, countsubs(Arg0)); }
	void test_case_6() { string Arr0[] = {"000000100000100110001000110001001000","010100001000000000000001001010000000",
"101000100010000100000000010000000010","110001101110110000010000000001000101",
"000001000000010000000110001010100101","100100010001010000000000000010000010",
"111001000000111111001001011001010000","100001100000110001011110000001010001",
"111000000001100100000000000011100000","111010110000011000100000000001101000",
"001000100000001010001001001000011001","110111001101000100000101000100100100",
"100111000010100110001100101101000001","000010100000110111000000000100100000",
"000100001010000000010010000000100100","001100000010010000000100100001100000",
"001000100100000100001000000100010001","011010000110001000000001010011001100",
"000100011111100000000010010010110000","000001010101001010011111100000000110",
"000010000010001010100100010001100000","010001011000000000000100000110000001",
"010000000100100000000000000000011000","100101001000001100000100001000000001",
"100010000000000000000001000000010000","101010000010001001011011000000000100",
"000010000000011010111000010111100100","010001101111000100100101110000100000",
"000110010000000100000000000010000010","111000001000000010010000011100000100",
"000010101100100100010100000000000000","110010001000100100010000000000000000",
"011000100000000100110101101100100001","000100000011001110100000001100111010",
"000110001101100010100000000000010000","000110010010011001010010100110001001",
"110001100000010000000000100100010110","001110011000110000100110000011001000",
"000001000100000110011100000100000101","100001000000010000100000101001101100",
"011010110000011000110011111101011110","010001100010101100000101000000010001",
"011011000101000001101110100011110110","101000001100010010001100011000000010",
"001111000011100001110000010010010001","010000001010010000010000101000110000",
"001101100001000101000100010011001110","001010110110101000010100101101010101",
"000100010111110010010100101000100101","100010000000010101111010010000110001"}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 1086198432923648LL; verify_case(6, Arg1, countsubs(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
	Gxor ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
