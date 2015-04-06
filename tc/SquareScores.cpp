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
 

class SquareScores
{
	public:
	double calcexpectation(vector <int> p, string s)
	{
		double ps[1001];
		ps[0] = 0;
		for (int i = 1; i <= 1000; ++i)
		{
			ps[i] = ps[i - 1] + i;
		}
		double a[s.length()][p.size()];
		double sum[s.length()];
		memset(a, 0, sizeof(a));
		memset(sum, 0, sizeof(sum));
		for (int i = 0; i < s.length(); ++i)
		{
			if (s[i] == '?')
			{
				for (int j = 0; j < p.size(); ++j)
				{
					double pn = p[j] / 100.0;
					for (int k = i - 1; ; --k)
					{
						if (k < 0)
						{
							a[i][j] += pn * ps[i - k];
							break;
						}
						else if (s[k] == '?')
						{
							for (int kk = 0; kk < p.size(); ++kk)
							{
								if (kk == j)
								{
									continue;
								}
								a[i][j] += pn * (a[k][kk] + p[kk] / 100.0 * ps[i - k]);
							}
							pn *= p[j] / 100.0;
						}
						else if (s[k] - 'a' != j)
						{
							a[i][j] += pn * (sum[k] + ps[i - k]);
							break;
						}
					}
				}
			}
			else
			{
				double pn = 1.0;
				int j = s[i] - 'a';
				for (int k = i - 1; ; --k)
				{
					if (k < 0)
					{
						a[i][j] += pn * ps[i - k];
						break;
					}
					else if (s[k] == '?')
					{
						for (int kk = 0; kk < p.size(); ++kk)
						{
							if (kk == j)
							{
								continue;
							}
							a[i][j] += pn * (a[k][kk] + p[kk] / 100.0 * ps[i - k]);
						}
						pn *= p[j] / 100.0;
					}
					else if (s[k] - 'a' != j)
					{
						a[i][j] += pn * (sum[k] + ps[i - k]);
						break;
					}
				}
			}
			for (int j = 0; j < p.size(); ++j)
			{
				sum[i] += a[i][j];
			}
		}
		// for (int i = 0; i < s.length(); ++i)
		// {
		// 	for (int j = 0; j < p.size(); ++j)
		// 	{
		// 		printf("%.2lf ", a[i][j]);
		// 	}
		// 	printf("%lf \n", sum[i] );
		// }
		return sum[s.length() - 1];
	}
 
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1, 99}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "aaaba"; double Arg2 = 8.0; verify_case(0, Arg2, calcexpectation(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {10, 20, 70}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "aa?bbbb"; double Arg2 = 15.0; verify_case(1, Arg2, calcexpectation(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {10, 20, 30, 40}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "a??c?dc?b"; double Arg2 = 11.117; verify_case(2, Arg2, calcexpectation(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {25, 25, 21, 2, 2, 25}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "a??b???????ff??e"; double Arg2 = 21.68512690712425; verify_case(3, Arg2, calcexpectation(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {4, 4, 4, 3, 4, 4, 4, 4, 4, 4, 3, 4, 4, 4, 3, 4, 4, 4, 4, 4, 4, 4, 3, 4, 4, 4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "??????????????????????????????"; double Arg2 = 31.16931963781721; verify_case(4, Arg2, calcexpectation(Arg0, Arg1)); }
	void test_case_5() { int Arr0[] = {4, 3, 4, 3, 8, 2, 4, 3, 4, 4, 3, 2, 4, 4, 3, 4, 2, 4, 7, 6, 4, 4, 3, 4, 4, 3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "makigotapresentfromniko"; double Arg2 = 23.0; verify_case(5, Arg2, calcexpectation(Arg0, Arg1)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main(){
	SquareScores ___test;
	___test.run_test(-1);
	getch();
	return 0;
}
// END CUT HERE
