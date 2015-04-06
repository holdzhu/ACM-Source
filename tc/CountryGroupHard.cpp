// BEGIN CUT HERE

#include <conio.h>
#include <sstream>
/*
*/
 #define debuging
#ifdef debuging
#define FIN  {freopen("new.in" , "r" , stdin) ;}
#define FOUT {freopen("new.out" , "w" , stdout) ;}
#define OUT(x)  {cout<< #x << "  : " << x <<endl ;}
#define ERR(x)  {cout<<"#error: "<< x ; while(1) ;}
#endif
// END CUT HERE
#ifndef debuging
#define FIN  ;
#define FOUT ;
#define OUT(x)  ;
#define ERR(x)  ;
#endif
#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std ;
#define For(i , n) for(int i = 0 ; i < (n) ; ++i)
#define SZ(x)  (int)((x).size())
typedef long long lint ;
const int maxint = -1u>>2 ;
const double eps = 1e-6 ;
 

class CountryGroupHard
{
	public:
	string solve(vector <int> a)
	{
		int l = a.size();
		int dp[l + 1];
		dp[l] = 1;
		for (int i = l - 1; i >= 0; --i)
		{
			dp[i] = 0;
			int t = 0;
			for (int j = i; j < l && (t == 0 || a[j] == 0 || t == a[j]); ++j)
			{
				if (a[j])
				{
					t = a[j];
				}
				if (j - i + 1 == t || t == 0)
				{
					dp[i] += dp[j + 1];
				}
			}
		}
		return dp[0] == 1 ? "Sufficient" : "Insufficient";
	}
 
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {0,2,3,0,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Sufficient"; verify_case(0, Arg1, solve(Arg0)); }
	void test_case_1() { int Arr0[] = {0,2,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Insufficient"; verify_case(1, Arg1, solve(Arg0)); }
	void test_case_2() { int Arr0[] = {0,3,0,0,3,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Sufficient"; verify_case(2, Arg1, solve(Arg0)); }
	void test_case_3() { int Arr0[] = {0,0,3,3,0,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Insufficient"; verify_case(3, Arg1, solve(Arg0)); }
	void test_case_4() { int Arr0[] = {2,2,0,2,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Sufficient"; verify_case(4, Arg1, solve(Arg0)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main(){
	CountryGroupHard ___test;
	___test.run_test(-1);
	getch();
	return 0;
}
// END CUT HERE
