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
 

class Similars
{
	public:
	int num[1024];
	int maxsim(int L, int R)
	{
		memset(num, 0, sizeof num);
		for (int i = L; i <= R; ++i)
		{
			int nums[6];
			memset(nums, 0, sizeof nums);
			int t = i;
			int p = 0;
			while (t)
			{
				nums[p++] = t % 10;
				t /= 10;
			}
			sort(nums, nums + p);
			p = unique(nums, nums + p) - nums;
			for (int j = 0; j < 1 << p; ++j)
			{
				t = j;
				int ans = 0;
				for (int k = 0; k < p; ++k)
				{
					if (t & 1)
					{
						ans += 1 << nums[k];
					}
					t >>= 1;
				}
				num[ans]++;
			}
		}
		int maxn = 0;
		for (int i = 0; i < 1024; ++i)
		{
			if (num[i] > 1)
			{
				int t = i;
				int c = 0;
				while (t)
				{
					c += t & 1;
					t >>= 1;
				}
				maxn = max(maxn, c);
			}
		}
		return maxn;
	}
 
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; int Arg1 = 10; int Arg2 = 1; verify_case(0, Arg2, maxsim(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 1; int Arg1 = 99; int Arg2 = 2; verify_case(1, Arg2, maxsim(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 99; int Arg1 = 100; int Arg2 = 0; verify_case(2, Arg2, maxsim(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 1000; int Arg1 = 1010; int Arg2 = 2; verify_case(3, Arg2, maxsim(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 444; int Arg1 = 454; int Arg2 = 2; verify_case(4, Arg2, maxsim(Arg0, Arg1)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main(){
	Similars ___test;
	___test.run_test(-1);
	getch();
	return 0;
}
// END CUT HERE
