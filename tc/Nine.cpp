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
#include <set>
using namespace std ;
#define For(i , n) for(int i = 0 ; i < (n) ; ++i)
#define SZ(x)  (int)((x).size())
typedef long long lint ;
const int maxint = -1u>>2 ;
const double eps = 1e-6 ;
 

class Nine
{
	public:
	long long ninth[5001];
	const int mod = 1000000007;
	int dfs(int de, long long c, )
	{
		if (de > 0)
		{
			
		}
	}
	int count(int N, vector <int> d)
	{
		ninth[0] = 0;
		for (int i = 1; i <= 5000; ++i)
		{
			ninth[i] = ninth[i - 1] * 9 % mod;
		}
		int l = d.size();
		bool b[l][N];
		for (int i = 0; i < l; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				b[i][j] = d[i] & 1;
				d[i] >>= 1;
			}
		}
		long long dp[l][9];
		int lp[N];
		memset(lp, -1, sizeof(lp));
		for (int i = 0; i < l; ++i)
		{
			bool flag = false;
			for (int j = 0; j < N; ++j)
			{
				if (b[i][j])
				{
					flag = true;
					break;
				}
			}
			if (flag)
			{
				long long t[9];
				memset(t, 0, sizeof(t));
				set<int> s;
				for (int j = 0; j < N; ++j)
				{
					if (lp[j] != -1)
					{
						s.insert(lp[j]);
					}
				}
				if (s.size() == 0)
				{
					t[0] = 2;
					for (int j = 1; j < 9; ++j)
					{
						t[j] = 1;
					}
				}
				else
				{
					int tmp[s.size()];
					int pos = 0;
					for (set<int>::iterator i = s.begin(); i != s.end(); ++i)
					{
						tmp[pos++] = *i;
					}
					dfs(s.size(), 1, )
				}
			}
		}
		return int() ;
	}
 
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arr1[] = {1,2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 4; verify_case(0, Arg2, count(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 2; int Arr1[] = {1,2,3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 16; verify_case(1, Arg2, count(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 1; int Arr1[] = {0,0,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 200; verify_case(2, Arg2, count(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 5; int Arr1[] = {1,3,5,8,24,22,25,21,30,2,4,0,6,7,9,11,14,13,12,15,18,17,16,19,26,29,31,28,27,10,20,23}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 450877328; verify_case(3, Arg2, count(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 5; int Arr1[] = {31,31,31,31,31}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 11112; verify_case(4, Arg2, count(Arg0, Arg1)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main(){
	Nine ___test;
	___test.run_test(-1);
	getch();
	return 0;
}
// END CUT HERE
