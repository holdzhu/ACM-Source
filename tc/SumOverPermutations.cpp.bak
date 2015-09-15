// BEGIN CUT HERE
/*

*/
// END CUT HERE
#line 7 "SumOverPermutations.cpp"
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


class SumOverPermutations
{
	const int mod = 1000000007;
	long long fac[5001];
	long long inv[5001];
	long long facinv[5001];
	long long dp[5001];
	long long C(long long n, long long m)
	{
		if (m < 0 || m > n)
		{
			return 0;
		}
		return fac[n] * facinv[m] % mod * facinv[n - m] % mod;
	}
	void init(int n)
	{
		fac[0] = fac[1] = inv[0] = inv[1] = facinv[0] = facinv[1] = 1;
		for (int i = 2; i <= n; ++i)
		{
			fac[i] = fac[i - 1] * i % mod;
			inv[i] = inv[mod % i] * (mod - mod / i) % mod;
			facinv[i] = facinv[i - 1] * inv[i] % mod;
		}
	}
	public:
	int findSum(int n)
	{
		init(n);
		dp[1] = n;
		for (int i = 2; i <= n; ++i)
		{
			dp[i] = 0;
			for (int j = 1; j <= i; ++j)
			{
				if (j == 1 || j == i)
				{
					dp[i] = (dp[i] + dp[i - 1] * (n - 1)) % mod;
				}
				else
				{
					dp[i] = (dp[i] + dp[j - 1] * dp[i - j] % mod * C(i - 1, j - 1) % mod * (n - 2)) % mod;
				}
			}
		}
		return dp[n];
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arg1 = 4; verify_case(0, Arg1, findSum(Arg0)); }
	void test_case_1() { int Arg0 = 3; int Arg1 = 66; verify_case(1, Arg1, findSum(Arg0)); }
	void test_case_2() { int Arg0 = 10; int Arg1 = 58310114; verify_case(2, Arg1, findSum(Arg0)); }
	void test_case_3() { int Arg0 = 3900; int Arg1 = 940560814; verify_case(3, Arg1, findSum(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
	SumOverPermutations ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
