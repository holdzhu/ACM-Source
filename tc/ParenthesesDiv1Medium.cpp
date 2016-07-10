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

class ParenthesesDiv1Medium
{
public:
	int cntl, cntr;
	void deal(string s)
	{
		int cnt = 0, l = 0, r = 0;
		for (int i = 0; i < s.size(); ++i)
		{
			if (s[i] == '(')
				cnt++;
			else
				if (cnt == 0)
					r++;
				else
					cnt--;
		}
		l = cnt;
		if (l & 1)
		{
			cntl += l / 2 + 1;
			cntr += r / 2 + 1;
		}
		else
		{
			cntl += l / 2;
			cntr += r / 2;
		}
	}
	int minSwaps(string s, vector <int> L, vector <int> R)
	{
		int n = s.size();
		int m = L.size();
		cntl = cntr = 0;
		vector<int> stk;
		vector<pair<int, int> > v;
		vector<vector<int> > add(n + 1);
		vector<vector<int> > subtract(n + 1);
		for (int i = 0; i < m; ++i)
		{
			add[L[i]].push_back(i);
			subtract[R[i]].push_back(i);
			if ((R[i] - L[i]) % 2 == 0)
				return -1;
		}
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < add[i].size(); ++j)
			{
				if (L[add[i][j]] > R[add[i][j]])
					continue;
				stk.push_back(add[i][j]);
			}
			for (int j = 0; j < subtract[i].size(); ++j)
			{
				if (L[subtract[i][j]] > R[subtract[i][j]])
					continue;
				if (stk.back() == subtract[i][j])
				{
					v.push_back(make_pair(L[subtract[i][j]], -R[subtract[i][j]]));
					stk.pop_back();
				}
				else
				{
					while (stk.size() && stk.back() != subtract[i][j])
					{
						v.push_back(make_pair(L[stk.back()], -i));
						add[i + 1].push_back(stk.back());
						L[stk.back()] = i + 1;
						stk.pop_back();
					}
					v.push_back(make_pair(L[stk.back()], -i));
					stk.pop_back();
				}
			}
		}
		sort(v.begin(), v.end());
		v.erase(unique(v.begin(), v.end()), v.end());
		for (int i = 0; i < v.size(); ++i)
		{
			v[i].second = -v[i].second;
			if ((v[i].second - v[i].first) % 2 == 0)
				return -1;
		}
		stack<pair<string, int> > st;
		int reml = 0, remr = 0;
		for (int i = 0, j = 0; i < n; ++i)
		{
			while (j < v.size() && v[j].first == i)
			{
				st.push(make_pair(string(), j));
				j++;
			}
			if (st.size())
				st.top().first += s[i];
			else
			{
				if (s[i] == '(')
					reml++;
				else
					remr++;
			}
			while (st.size() && v[st.top().second].second == i)
			{
				deal(st.top().first);
				st.pop();
			}
		}
		if (cntl < cntr)
		{
			if (cntr - cntl > reml)
				return -1;
		}
		else
		{
			if (cntl - cntr > remr)
				return -1;
		}
		return max(cntl, cntr);
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = ")("; int Arr1[] = {0,0,0,0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1,1,1,1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 1; verify_case(0, Arg3, minSwaps(Arg0, Arg1, Arg2)); }
	void test_case_1() { string Arg0 = "(())"; int Arr1[] = {0,2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1,3}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 1; verify_case(1, Arg3, minSwaps(Arg0, Arg1, Arg2)); }
	void test_case_2() { string Arg0 = "(((())"; int Arr1[] = {0,2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1,3}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 2; verify_case(2, Arg3, minSwaps(Arg0, Arg1, Arg2)); }
	void test_case_3() { string Arg0 = "((((((((("; int Arr1[] = {0,2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1,3}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = -1; verify_case(3, Arg3, minSwaps(Arg0, Arg1, Arg2)); }
	void test_case_4() { string Arg0 = "()()()()"; int Arr1[] = {0,0,0,0,2,2,2,4,4,6}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1,3,5,7,3,5,7,5,7,7}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 0; verify_case(4, Arg3, minSwaps(Arg0, Arg1, Arg2)); }
	void test_case_5() { string Arg0 = ")()(()()((())()()()()()()))(()())()()()("; int Arr1[] = {3,5,17,25,35}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {12,10,30,30,38}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 3; verify_case(5, Arg3, minSwaps(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
	ParenthesesDiv1Medium ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
