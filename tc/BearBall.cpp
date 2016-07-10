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

class BearBall
{
public:
	int countThrows(vector <int> x, vector <int> y)
	{
		int n = x.size();
		int ans = n * (n - 1);
		bool flag = false;
		for (int i = 0; i < n; ++i)
		{
			map<pair<int, int>, pair<pair<int, int>, int> > mp;
			for (int j = 0; j < n; ++j)
			{
				if (i == j)
					continue;
				int dx = x[i] - x[j];
				int dy = y[i] - y[j];
				int g = __gcd(dx, dy);
				dx /= g;
				dy /= g;
				if (dx < 0 || (dx == 0 && dy < 0))
					dx = -dx, dy = -dy;
				if (!mp.count(make_pair(dx, dy)))
					mp[{dx, dy}] = {{x[i], y[i]}, 1};
				auto &it = mp[{dx, dy}];
				pair<int, int> p = {x[j], y[j]};
				it.first = min(it.first, p);
				it.second++;
			}
			for (auto &p: mp)
				if (p.second.first == make_pair(x[i], y[i]))
				{
					if (p.second.second == n)
						flag = true;
					ans += (p.second.second - 1) * (p.second.second - 2);
				}
		}
		if (flag)
		{
			ans = 0;
			for (int i = 0; i < n; ++i)
				for (int j = 0; j < n; ++j)
					ans += abs(i - j);
		}
		return ans;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1,4,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,10,7}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 6; verify_case(0, Arg2, countThrows(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {0,0,0,1,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0,1,2,0,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 22; verify_case(1, Arg2, countThrows(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {5,7,9,11}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {4,3,2,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 20; verify_case(2, Arg2, countThrows(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {10,10,50,50,90,90}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {5,17,5,17,5,17}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 34; verify_case(3, Arg2, countThrows(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {-100, -90, -80, -70, -85, -90, 0, 20}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {-5, -8, -13, -21, -13, -13, -13, -69}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 68; verify_case(4, Arg2, countThrows(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
	BearBall ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
