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
 

class BichromePainting
{
	public:
	string isThatPossible(vector <string> board, int k)
	{
		int n = board.size();
		bool vis[n][n];
		memset(vis, 0, sizeof(vis));
		while (1)
		{
			bool flag = false;
			bool win = true;
			for (int i = 0; i < n - k + 1; ++i)
			{
				for (int j = 0; j < n - k + 1; ++j)
				{
					if (!vis[i][j])
					{
						int c = 0;
						int q = 0;
						for (int i2 = 0; i2 < k; ++i2)
						{
							for (int j2 = 0; j2 < k; ++j2)
							{
								if (board[i + i2][j + j2] == 'B')
								{
									c++;
									win = false;
								}
								else if (board[i + i2][j + j2] == '?')
								{
									q++;
								}
							}
						}
						if (c + q == k * k || c == 0)
						{
							flag = true;
							vis[i][j] = true;
							for (int i2 = 0; i2 < k; ++i2)
							{
								for (int j2 = 0; j2 < k; ++j2)
								{
									board[i + i2][j + j2] = '?';
								}
							}
						}
					}
				}
			}
			if (win)
			{
				return "Possible";
			}
			if (!flag)
			{
				return "Impossible";
			}
		}
	}
 
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"BBBW",
 "BWWW",
 "BWWW",
 "WWWW"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; string Arg2 = "Possible"; verify_case(0, Arg2, isThatPossible(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"BW",
 "WB"}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; string Arg2 = "Impossible"; verify_case(1, Arg2, isThatPossible(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"BWBWBB",
 "WBWBBB",
 "BWBWBB",
 "WBWBBB",
 "BBBBBB",
 "BBBBBB"}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; string Arg2 = "Possible"; verify_case(2, Arg2, isThatPossible(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"BWBWBB",
 "WBWBWB",
 "BWBWBB",
 "WBWBWB",
 "BWBWBB",
 "BBBBBB"}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; string Arg2 = "Impossible"; verify_case(3, Arg2, isThatPossible(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = {"BWBWBB",
 "WBWBWB",
 "BWBWBB",
 "WBWBWB",
 "BWBWBB",
 "BBBBBB"}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; string Arg2 = "Possible"; verify_case(4, Arg2, isThatPossible(Arg0, Arg1)); }
	void test_case_5() { string Arr0[] = {"BB",
 "BB"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; string Arg2 = "Possible"; verify_case(5, Arg2, isThatPossible(Arg0, Arg1)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main(){
	BichromePainting ___test;
	___test.run_test(-1);
	getch();
	return 0;
}
// END CUT HERE
