// BEGIN CUT HERE
/*

*/
// END CUT HERE
#line 7 "LimitedMemorySeries1.cpp"
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


class LimitedMemorySeries1
{
	vector<int> query;
	int n, x0, a, b;
	long long sum;
	void dfs(int L, int R, int l, int r)
	{
		int cnt = 0, le = 0;
		int M = (L + R) >> 1;
		long long t = x0;
		for (int i = 0; i < n; ++i)
		{
			if (t == M)
			{
				cnt++;
			}
			else if (t < M)
			{
				le++;
			}
			t = (t * a + b) % 1000000007;
		}
		int pos1 = lower_bound(query.begin() + l, query.begin() + r + 1, le) - query.begin();
		int pos2 = lower_bound(query.begin() + l, query.begin() + r + 1, le + cnt) - query.begin();
		if (pos1 < pos2)
		{
			sum += M * (pos2 - pos1);
		}
		if (pos1 > l) dfs(L, M - 1, l, pos1 - 1);
		if (r >= pos2) dfs(M + 1, R, pos2, r);
	}
	int sum[200000];
	void init()
	{
		for (int i = 0; i < 200000; ++i)
		{
			long long t = x0;
			sum[i] = 0;
			for (int j = 0; j < n; ++j)
			{
				if (t < i * 5000)
				{
					sum[i]++;
				}
				t = (t * a + b) % 1000000007;
			}
		}
	}
	public:
	long long getSum(int n, int x0, int a, int b, vector <int> query)
	{
		sum = 0;
		sort(query.begin(), query.end());
		this->query = query;
		this->n = n;
		this->x0 = x0;
		this->a = a;
		this->b = b;
		init();
		dfs(0, 1e9 + 6, 0, query.size() - 1);
		return sum;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 5; int Arg1 = 100; int Arg2 = 1; int Arg3 = 5; int Arr4[] = {0,3}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); long long Arg5 = 215LL; verify_case(0, Arg5, getSum(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_1() { int Arg0 = 5; int Arg1 = 123456789; int Arg2 = 987654321; int Arg3 = 1000000006; int Arr4[] = {0,1,2,3}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); long long Arg5 = 733028692LL; verify_case(1, Arg5, getSum(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_2() { int Arg0 = 5000000; int Arg1 = 482995837; int Arg2 = 512849030; int Arg3 = 120583724; int Arr4[] = {4854010,3139503,1855546,219904,846357,2624639,891260,217467,4940091,4802760,2424821,424076,
 3848272,2062765,2922407,4850301,1279972,4929307,2035456,3562859,1749594,4089499,3797495,1013980,
 1650805,1245213,3020379,4661668,427170,1176815,292944,2435328,420809,4170355,2635197,3940607,
 4311718,2098572,4868054,30319,4588969,1460677,1335028,3921495,3621970,4459335,966000,3686977,
 2316560,1634961,2280624,1940395,3321546,3168811,1856547,3859093,4340475,1382782,3482928,2517843,
 185008,1135373,2821050,3260484,4821220,1700954,3243343,2183615,394339,2630121,1811267,1060542,
 3898314,892312,2015580,11161,4965095,2128470,2320933,1095881,3938450,1887098,975426,2098073,3300937,
 1145560,2894728,1026181,3259403,4509345,3610224,3584456,1877483,2665752,2243671,616205,504849,3068426,
 1471925,4144568}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); long long Arg5 = 49684994148LL; verify_case(2, Arg5, getSum(Arg0, Arg1, Arg2, Arg3, Arg4)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
	LimitedMemorySeries1 ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
