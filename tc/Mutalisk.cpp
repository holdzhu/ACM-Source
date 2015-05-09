// BEGIN CUT HERE
/*

*/
// END CUT HERE
#line 7 "Mutalisk.cpp"
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


class Mutalisk
{
	public:
	int minimalAttacks(vector <int> x)
	{
		int n = x.size();
		int minc = 0;
		vector<int> a;
		int sum = 0;
		for (int i = 0; i < n; ++i)
		{
			sum += x[i];
			a.push_back(x[i]);
		}
		int ans;
		n = a.size();
		sort(a.begin(), a.end(), greater<int>());
		for (ans = 0; n; ++ans)
		{
			a[0] -= 9;
			int p1 = 0;
			int p2 = -1;
			int p3 = -1;
			if (a.size() > 1)
			{
				for (int i = 1; i < n; ++i)
				{
					if (a[i] < 9)
					{
						a[i] -= 3;
						p2 = i;
						break;
					}
				}
				if (p2 == -1)
				{
					a[n - 1] -= 3;
					p2 = n - 1;
				}
			}
			if (a.size() > 2)
			{
				for (int i = 1; i < n; ++i)
				{
					if (a[i] < 3)
					{
						a[i] -= 1;
						p3 = i;
						break;
					}
				}
				if (p3 == -1)
				{
					if (p2 == n - 1)
					{
						a[n - 2] -= 3;
						p2 = n - 2;
						a[n - 1] += 2;
						p3 = n - 1;
					}
					else
					{
						a[n - 1] -= 1;
						p3 = n - 1;
					}
				}
			}
			sort(a.begin(), a.end(), greater<int>());
			n = a.size();
			for (int i = 0; i < a.size(); ++i)
			{
				printf("%d ", a[i]);
				if (a[i] <= 0)
				{
					n = i;
					break;
				}
			}
			printf("\n");
		}
		return ans;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {12,10,4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(0, Arg1, minimalAttacks(Arg0)); }
	void test_case_1() { int Arr0[] = {54,18,6}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 6; verify_case(1, Arg1, minimalAttacks(Arg0)); }
	void test_case_2() { int Arr0[] = {1,1,1,1,1,1,1,1,1,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(2, Arg1, minimalAttacks(Arg0)); }
	void test_case_3() { int Arr0[] = {55,60,53}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 13; verify_case(3, Arg1, minimalAttacks(Arg0)); }
	void test_case_4() { int Arr0[] = {60}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 7; verify_case(4, Arg1, minimalAttacks(Arg0)); }
	void test_case_5() { int Arr0[] = {60,60,60,60,60,60,60,60,60,60,60,60,60,60,60,60,60,60,60,60}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 93; verify_case(5, Arg1, minimalAttacks(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
	Mutalisk ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
