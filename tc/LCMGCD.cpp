#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <string>
#include <utility>
#include <vector>
using namespace std;

class LCMGCD
{
public:
	string isPossible(vector <int> x, int t)
	{
		int n = x.size();
		vector<int> p1(n);
		vector<int> p2(n);
		int f1 = 0;
		int f2 = 0;
		while (t % 2 == 0)
		{
			f1++;
			t /= 2;
		}
		while (t % 3 == 0)
		{
			f2++;
			t /= 3;
		}
		for (int i = 0; i < n; ++i)
		{
			while (x[i] % 2 == 0)
			{
				p1[i]++;
				x[i] /= 2;
			}
			while (x[i] % 3 == 0)
			{
				p2[i]++;
				x[i] /= 3;
			}
		}
		int x1 = 1e9;
		int y1 = 1e9;
		int x2 = 1e9;
		int y2 = 1e9;
		for (int i = 0; i < n; ++i)
		{
			if (p1[i] <= f1 && p2[i] >= f2)
			{
				x1 = min(x1, p1[i]);
				y1 = min(y1, p2[i]);
			}
			if (p1[i] >= f1 && p2[i] <= f2)
			{
				x2 = min(x2, p1[i]);
				y2 = min(y2, p2[i]);
			}
		}
		if (max(x1, x2) == f1 && max(y1, y2) == f2)
			return "Possible";
		else
		{
			int x1 = -1e9;
			int y1 = -1e9;
			int x2 = -1e9;
			int y2 = -1e9;
			for (int i = 0; i < n; ++i)
			{
				if (p1[i] <= f1 && p2[i] >= f2)
				{
					x1 = max(x1, p1[i]);
					y1 = max(y1, p2[i]);
				}
				if (p1[i] >= f1 && p2[i] <= f2)
				{
					x2 = max(x2, p1[i]);
					y2 = max(y2, p2[i]);
				}
			}
			printf("%d %d %d %d\n", x1, x2, y1, y2);
			if (min(x1, x2) == f1 && min(y1, y2) == f2)
				return "Possible";
			else
				return "Impossible";
		}
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); if ((Case == -1) || (Case == 7)) test_case_7(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {2,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 6; string Arg2 = "Possible"; verify_case(0, Arg2, isPossible(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {4,9}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 6; string Arg2 = "Impossible"; verify_case(1, Arg2, isPossible(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {6,12,24,18,36,72,54,108,216}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 36; string Arg2 = "Possible"; verify_case(2, Arg2, isPossible(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {6,27,81,729}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 6; string Arg2 = "Impossible"; verify_case(3, Arg2, isPossible(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; string Arg2 = "Possible"; verify_case(4, Arg2, isPossible(Arg0, Arg1)); }
	void test_case_5() { int Arr0[] = {72,16,16,16,16,16,27,27,27,27,27,27,27,27,27}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 72; string Arg2 = "Possible"; verify_case(5, Arg2, isPossible(Arg0, Arg1)); }
	void test_case_6() { int Arr0[] = {100663296, 544195584, 229582512, 59049}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 60466176; string Arg2 = "Possible"; verify_case(6, Arg2, isPossible(Arg0, Arg1)); }
	void test_case_7() { int Arr0[] = {2,4,8,16,32,64}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 256; string Arg2 = "Impossible"; verify_case(7, Arg2, isPossible(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
	LCMGCD ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
