// BEGIN CUT HERE
/*

*/
// END CUT HERE
#line 7 "WalkOverATree.cpp"
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


class WalkOverATree
{
	int l;
	int dp1[51][101];
	int dp2[51][101];
	int tmp[51][101];
	vector<int> G[51];
	void dfs1(int u)
	{
		memset(dp1[u], 0, sizeof dp1[u]);
		dp1[u][0] = 1;
		for (int i = 0; i < G[u].size(); ++i)
		{
			int v = G[u][i];
			dfs1(v);
			for (int j = l; j >= 0; --j)
			{
				for (int k = 2; k <= j; k += 2)
				{
					dp1[u][j] = max(dp1[u][j], dp1[v][k - 2] + dp1[u][j - k]);
				}
			}
		}
	}
	void dfs2(int u)
	{
		memset(dp2[u], 0, sizeof dp2[u]);
		dp2[u][0] = 1;
		for (int i = 0; i < G[u].size(); ++i)
		{
			memset(tmp[u], 0, sizeof tmp[u]);
			tmp[u][0] = 1;
			for (int j = 0; j < G[u].size(); ++j)
			{
				if (i == j)
				{
					continue;
				}
				for (int k = l; k >= 0; --k)
				{
					for (int l2 = 2; l2 <= k; l2 += 2)
					{
						tmp[u][k] = max(tmp[u][k], dp1[G[u][j]][l2 - 2] + tmp[u][k - l2]);
					}
				}
			}
			int v = G[u][i];
			dfs2(G[u][i]);
			for (int j = l; j >= 0; --j)
			{
				dp2[u][j] = max(dp2[u][j], tmp[u][j]);
				for (int k = 1; k <= j; ++k)
				{
					dp2[u][j] = max(dp2[u][j], dp2[v][k - 1] + tmp[u][j - k]);
				}
			}
		}
	}
	public:
	int maxNodesVisited(vector <int> parent, int L)
	{
		for (int i = 0; i < parent.size() + 1; ++i)
		{
			G[i].clear();
		}
		for (int i = 0; i < parent.size(); ++i)
		{
			G[parent[i]].push_back(i + 1);
		}
		l = L;
		dfs1(0);
		dfs2(0);
		int ans = 0;
		for (int i = 0; i <= l; ++i)
		{
			ans = max(ans, dp1[0][i]);
			ans = max(ans, dp2[0][i]);
		}
		return ans;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); if ((Case == -1) || (Case == 7)) test_case_7(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {0, 0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 2; verify_case(0, Arg2, maxNodesVisited(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {0, 0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arg2 = 3; verify_case(1, Arg2, maxNodesVisited(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {0, 1, 2, 3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 3; verify_case(2, Arg2, maxNodesVisited(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {0,0,0,0,2,4,2,3,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 2; verify_case(3, Arg2, maxNodesVisited(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {0,0,1,2,3,2,3,1,3,0,1,8,6,8,0,5,15,0,9}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; int Arg2 = 5; verify_case(4, Arg2, maxNodesVisited(Arg0, Arg1)); }
	void test_case_5() { int Arr0[] = {0,0,0,1,1,3,5,1,4,5,2,2,10,5,10,10,11,13,8,3,18,15,20,20,23,8,11,26,4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 26; int Arg2 = 17; verify_case(5, Arg2, maxNodesVisited(Arg0, Arg1)); }
	void test_case_6() { int Arr0[] = {0, 0, 2, 0}
; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 100; int Arg2 = 5; verify_case(6, Arg2, maxNodesVisited(Arg0, Arg1)); }
	void test_case_7() { int Arr0[] = {0, 0, 2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; int Arg2 = 4; verify_case(7, Arg2, maxNodesVisited(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
	WalkOverATree ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
