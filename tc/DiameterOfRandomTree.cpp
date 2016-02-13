// BEGIN CUT HERE
/*

*/
// END CUT HERE
#line 7 "DiameterOfRandomTree.cpp"
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


class DiameterOfRandomTree
{
	long double C(int n, int m)
	{
		if (m < 0 || m > n || n < 0)
		{
			return 0;
		}
		long double res = 1;
		for (int i = 0; i < n; ++i)
		{
			res *= (i + 1);
		}
		for (int i = 0; i < m; ++i)
		{
			res /= (i + 1);
		}
		for (int i = 0; i < (n - m); ++i)
		{
			res /= (i + 1);
		}
		return res;
	}
	public:
	double getExpectation(vector <int> a, vector <int> b)
	{
		int n = a.size() + 1;
		vector<vector<int> > dis;
		dis.resize(n);
		for (int i = 0; i < n; ++i)
		{
			dis[i].resize(n);
			for (int j = 0; j < n; ++j)
			{
				dis[i][j] = 1e9;
			}
			dis[i][i] = 0;
		}
		for (int i = 0; i < n - 1; ++i)
		{
			dis[a[i]][b[i]] = dis[b[i]][a[i]] = 1;
		}
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				for (int k = 0; k < n; ++k)
				{
					dis[j][k] = min(dis[j][k], dis[j][i] + dis[i][k]);
				}
			}
		}
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				printf("%d ", dis[i][j]);
			}
			printf("\n");
		}
		vector<long double> halfpow;
		halfpow.push_back(1);
		for (int i = 0; i < n; ++i)
		{
			halfpow.push_back(halfpow.back() * 0.5);
		}
		vector<vector<long double> > C;
		C.resize(2 * n + 1);
		C[0].push_back(1);
		C[0].push_back(0);
		for (int i = 1; i <= 2 * n; ++i)
		{
			C[i].push_back(1);
			for (int j = 1; j <= i; ++j)
			{
				C[i].push_back(C[i - 1][j - 1] + C[i - 1][j]);
			}
			C[i].push_back(0);
		}
		for (int i = 1; i <= 2 * n; ++i)
		{
			for (int j = 1; j <= i; ++j)
			{
				C[i][j] += C[i][j - 1];
			}
		}
		vector<long double> p;
		p.resize(2 * n + 1);
		for (int i = 0; i <= 2 * n; ++i)
		{
			p[i] = 1;
			for (int j = 0; j < n; ++j)
			{
				for (int k = 0; k < n; ++k)
				{
					if (i - dis[j][k] >= 0)
					{
						p[i] *= C[dis[j][k]][min(i - dis[j][k], dis[j][k])] * halfpow[dis[j][k]];
					}
					else
					{
						p[i] = 0;
					}
				}
			}
		}
		long double ans = 0;
		for (int i = 1; i <= n * 2; ++i)
		{
			printf("%.10f\n", (double)p[i]);
			ans += i * (p[i] - p[i - 1]);
		}
		return (double)ans;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {0,1,2,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,2,3,4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 6.0; verify_case(0, Arg2, getExpectation(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {0,0,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,2,3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 3.375; verify_case(1, Arg2, getExpectation(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {0,0,0,1,4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,2,3,4,5}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 6.25; verify_case(2, Arg2, getExpectation(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {0,0,0,0,0,0,0,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,2,3,4,5,6,7,8}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 3.9609375; verify_case(3, Arg2, getExpectation(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {0,0,0,1,2,3,5,6,8}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,2,3,4,5,6,7,8,9}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 10.53125; verify_case(4, Arg2, getExpectation(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
	DiameterOfRandomTree ___test;
	___test.run_test(0);
	return 0;
}
// END CUT HERE
