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

class ParenthesesDiv1Easy
{
public:
	vector <int> correct(string s)
	{
		vector<int> left, right;
		stack<int> pos;
		int n = s.size();
		if (n & 1)
			return vector<int>{-1};
		for (int i = 0; i < n; ++i)
		{
			if (s[i] == '(')
				pos.push(i);
			else
			{
				if (pos.size())
					pos.pop();
				else
					left.push_back(i);
			}
		}
		while (pos.size())
		{
			right.push_back(pos.top());
			pos.pop();
		}
		vector<int> ans;
		if (left.empty() && right.empty())
			return vector<int>();
		if (left.empty())
		{
			ans.push_back(right[right.size() / 2 - 1]);
			ans.push_back(right[0]);
		}
		else if (right.empty())
		{
			ans.push_back(left[0]);
			ans.push_back(left[left.size() / 2 - 1]);
		}
		else if (left.size() < right.size())
		{
			int t = left.size() + right.size();
			ans.push_back(left[0]);
			ans.push_back(left.back());
			ans.push_back(right[t / 2 - 1]);
			ans.push_back(right[0]);
		}
		else
		{
			int t = left.size() + right.size();
			ans.push_back(left[0]);
			ans.push_back(left[t / 2 - 1]);
			ans.push_back(right.back());
			ans.push_back(right[0]);
		}
		return ans;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arg0 = ")("; int Arr1[] = {0, 0, 1, 1 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, correct(Arg0)); }
	void test_case_1() { string Arg0 = "))))))(((((("; int Arr1[] = {0, 5, 6, 11 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, correct(Arg0)); }
	void test_case_2() { string Arg0 = "))()())()"; int Arr1[] = {-1 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, correct(Arg0)); }
	void test_case_3() { string Arg0 = ")()((("; int Arr1[] = {0, 0, 3, 3, 5, 5 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, correct(Arg0)); }
	void test_case_4() { string Arg0 = "()"; int Arr1[] = { }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(4, Arg1, correct(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
	ParenthesesDiv1Easy ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
