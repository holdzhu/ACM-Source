// BEGIN CUT HERE
/*

*/
// END CUT HERE
#line 7 "Treestrat.cpp"
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


class Treestrat
{
	public:
	int roundcnt(vector <int> tree, vector <int> A, vector <int> B)
	{
		int n = tree.size() + 1;
		vector<vector<int> > G;
		G.resize(n);
		for (int i = 0; i < n - 1; ++i)
		{
			int u = i + 1;
			int v = tree[i];
			G[u].push_back(v);
			G[v].push_back(u);
		}
		vector<int> step(n, -1);
		queue<pair<int, int> > q;
		for (int i = 0; i < B.size(); ++i)
		{
			q.push(make_pair(B[i], 0));
			step[B[i]] = 0;
		}
		while (!q.empty())
		{
			int u = q.front().first;
			int s = q.front().second;
			q.pop();
			for (int i = 0; i < G[u].size(); ++i)
			{
				int v = G[u][i];
				if (step[v] == -1)
				{
					step[v] = s + 1;
					q.push(make_pair(v, s + 1));
				}
			}
		}
		int ans = 1e9;
		for (int i = 0; i < A.size(); ++i)
		{
			int a = A[i];
			int mx = 0;
			vector<bool> vis(n, false);
			vis[a] = true;
			q.push(make_pair(a, 0));
			while (!q.empty())
			{
				int u = q.front().first;
				int s = q.front().second;
				q.pop();
				mx = max(mx, step[u]);
				if (step[u] <= s)
				{
					continue;
				}
				for (int i = 0; i < G[u].size(); ++i)
				{
					int v = G[u][i];
					if (!vis[v])
					{
						vis[v] = true;
						q.push(make_pair(v, s + 1));
					}
				}
			}
			ans = min(ans, mx);
		}
		return ans;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 1; verify_case(0, Arg3, roundcnt(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arr0[] = {0,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {2}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 2; verify_case(1, Arg3, roundcnt(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arr0[] = {0,0,0,3,4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 2; verify_case(2, Arg3, roundcnt(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arr0[] = {0,0,0,3,4,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {6}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 5; verify_case(3, Arg3, roundcnt(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arr0[] = {0,0,0,3,4,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {6,5}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 3; verify_case(4, Arg3, roundcnt(Arg0, Arg1, Arg2)); }
	void test_case_5() { int Arr0[] = {0,0,0,3,4,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {4,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {3,6}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 2; verify_case(5, Arg3, roundcnt(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
	Treestrat ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
