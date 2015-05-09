// BEGIN CUT HERE
/*

*/
// END CUT HERE
#line 7 "OddEvenTree.cpp"
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


class OddEvenTree
{
	public:
	vector <int> getTree(vector <string> x)
	{
		int n = x.size();
		vector<int> ans;
		for (int i = 0; i < n; ++i)
		{
			if (x[i][i] == 'O')
			{
				ans.push_back(-1);
				return ans;
			}
			for (int j = i + 1; j < n; ++j)
			{
				if (x[i][j] != x[j][i])
				{
					ans.push_back(-1);
					return ans;
				}
			}
		}
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				for (int k = 0; k < n; ++k)
				{
					int a = x[i][j] == 'E' ? 0 : 1;
					int b = x[i][k] == 'E' ? 0 : 1;
					int c = x[j][k] == 'E' ? 0 : 1;
					if (a ^ b ^ c == 1)
					{
						ans.push_back(-1);
						return ans;
					}
				}
			}
		}
		bool vis[n];
		memset(vis, 0, sizeof vis);
		vis[0] = true;
		for (int i = 0; i < n; ++i)
		{
			if (vis[i])
			{
				for (int j = 0; j < n; ++j)
				{
					if (!vis[j] && x[i][j] == 'O')
					{
						vis[j] = true;
						ans.push_back(i);
						ans.push_back(j);
					}
				}
			}
		}
		for (int i = 0; i < n; ++i)
		{
			if (!vis[i])
			{
				ans.push_back(-1);
				return ans;
			}
		}
		return ans;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"EOE",
 "OEO",
 "EOE"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0, 1, 2, 1 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, getTree(Arg0)); }
	void test_case_1() { string Arr0[] = {"EO",
 "OE"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0, 1 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, getTree(Arg0)); }
	void test_case_2() { string Arr0[] = {"OO",
 "OE"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {-1 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, getTree(Arg0)); }
	void test_case_3() { string Arr0[] = {"EO",
 "EE"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {-1 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, getTree(Arg0)); }
	void test_case_4() { string Arr0[] = {"EOEO",
 "OEOE",
 "EOEO",
 "OEOE"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0, 1, 0, 3, 2, 1 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(4, Arg1, getTree(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
	OddEvenTree ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
