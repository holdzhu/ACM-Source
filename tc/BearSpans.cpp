// BEGIN CUT HERE
/*

*/
// END CUT HERE
#line 7 "BearSpans.cpp"
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

int mx[1001];
bool mat[1001][1001];

class BearSpans
{
	public:
	void dfs(int n, int k, vector<int>& ans)
	{
		if (n == 1)
			return;
		for (int i = 1; i <= n / 2; ++i)
		{
			if (mx[i] + 1 >= k)
			{
				for (int j = 1; j <= i; ++j)
				{
					ans.push_back(j);
					ans.push_back(j + i);
				}
				for (int j = i * 2 + 1; j <= n; ++j)
				{
					ans.push_back(1);
					ans.push_back(j);
				}
				dfs(i, k - 1, ans);
				return;
			}
		}
	}
	vector <int> findAnyGraph(int n, int m, int k)
	{
		mx[1] = 0;
		for (int i = 2; i <= n; ++i)
			mx[i] = mx[i / 2] + 1;
		if (k > mx[n])
		{
			return {-1};
		}
		else
		{
			vector<int> ans;
			dfs(n, k, ans);
			if (m < ans.size() / 2)
				return {-1};
			for (int i = 1; i <= n; ++i)
			{
				for (int j = 1; j <= n; ++j)
				{
					mat[i][j] = mat[j][i] = 0;
				}
			}
			for (int i = 0; i < ans.size() / 2; ++i)
			{
				mat[ans[i * 2]][ans[i * 2 + 1]] = mat[ans[i * 2 + 1]][ans[i * 2]] = 1;
			}
			for (int i = 1; i <= n && m > ans.size() / 2; ++i)
			{
				for (int j = i + 1; j <= n && m > ans.size() / 2; ++j)
				{
					if (!mat[i][j])
					{
						ans.push_back(i);
						ans.push_back(j);
						mat[i][j] = mat[j][i] = true;
					}
				}
			}
			if (m > ans.size() / 2)
				return {-1};
			return ans;
		}
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arg0 = 17; int Arg1 = 22; int Arg2 = 1; int Arr3[] = {1, 2, 1, 3, 1, 4, 1, 5, 1, 6, 1, 7, 1, 8, 1, 9, 1, 10, 1, 11, 1, 12, 1, 13, 1, 14, 1, 15, 1, 16, 1, 17, 2, 3, 2, 8, 3, 9, 8, 9, 10, 12, 12, 14 }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(0, Arg3, findAnyGraph(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 9; int Arg1 = 12; int Arg2 = 3; int Arr3[] = {6, 5, 7, 6, 1, 2, 3, 4, 8, 9, 3, 5, 7, 4, 1, 9, 6, 2, 6, 1, 1, 8, 4, 5 }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(1, Arg3, findAnyGraph(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 9; int Arg1 = 12; int Arg2 = 7; int Arr3[] = {-1 }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(2, Arg3, findAnyGraph(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 1000; int Arg1 = 999; int Arg2 = 970; int Arr3[] = {-1 }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(3, Arg3, findAnyGraph(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 2; int Arg1 = 1; int Arg2 = 1; int Arr3[] = {1, 2 }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(4, Arg3, findAnyGraph(Arg0, Arg1, Arg2)); }
	void test_case_5() { int Arg0 = 3; int Arg1 = 2; int Arg2 = 1; int Arr3[] = {1, 2, 1, 3 }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(5, Arg3, findAnyGraph(Arg0, Arg1, Arg2)); }
	void test_case_6() { int Arg0 = 3; int Arg1 = 3; int Arg2 = 2; int Arr3[] = {-1 }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(6, Arg3, findAnyGraph(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
	BearSpans ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
