// BEGIN CUT HERE
/*

*/
// END CUT HERE
#line 7 "LuckySum.cpp"
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


class LuckySum
{
	long long dp[15][2][11];
	public:
	long long construct(string note)
	{
		long long ans = -1;
		for (int l1 = max((int)note.size() - 1, 1); l1 <= note.size(); ++l1)
		{
			for (int l2 = 1; l2 <= l1; ++l2)
			{
				memset(dp, -1, sizeof dp);
				dp[0][0][0] = 0;
				long long pow10 = 1;
				for (int i = 1; i <= note.size(); ++i)
				{
					if (note[note.size() - i] == '?')
					{
						for (int j = 0; j <= 1; ++j)
						{
							for (int k = 0; k < 10; ++k)
							{
								int mink2 = -1;
								long long mi = 1e18;
								for (int k2 = 0; k2 < 10; ++k2)
								{
									if ((10 * j + k == 1 || 10 * j + k == 0) && i > l1)
									{
										if (dp[i - 1][10 * j + k][k2] != -1 && dp[i - 1][10 * j + k][k2] < mi)
										{
											mi = dp[i - 1][10 * j + k][k2];
											mink2 = k2;
										}
									}
									if ((10 * j + k - 4 == 1 || 10 * j + k - 4 == 0) && i > l2 && i <= l1)
									{
										if (dp[i - 1][10 * j + k - 4][k2] != -1 && dp[i - 1][10 * j + k - 4][k2] < mi)
										{
											mi = dp[i - 1][10 * j + k - 4][k2];
											mink2 = k2;
										}
									}
									if ((10 * j + k - 7 == 1 || 10 * j + k - 7 == 0) && i > l2 && i <= l1)
									{
										if (dp[i - 1][10 * j + k - 7][k2] != -1 && dp[i - 1][10 * j + k - 7][k2] < mi)
										{
											mi = dp[i - 1][10 * j + k - 7][k2];
											mink2 = k2;
										}
									}
									if ((10 * j + k - 8 == 1 || 10 * j + k - 8 == 0) && i <= l2)
									{
										if (dp[i - 1][10 * j + k - 8][k2] != -1 && dp[i - 1][10 * j + k - 8][k2] < mi)
										{
											mi = dp[i - 1][10 * j + k - 8][k2];
											mink2 = k2;
										}
									}
									if ((10 * j + k - 11 == 1 || 10 * j + k - 11 == 0) && i <= l2)
									{
										if (dp[i - 1][10 * j + k - 11][k2] != -1 && dp[i - 1][10 * j + k - 11][k2] < mi)
										{
											mi = dp[i - 1][10 * j + k - 11][k2];
											mink2 = k2;
										}
									}
									if ((10 * j + k - 14 == 1 || 10 * j + k - 14 == 0) && i <= l2)
									{
										if (dp[i - 1][10 * j + k - 14][k2] != -1 && dp[i - 1][10 * j + k - 14][k2] < mi)
										{
											mi = dp[i - 1][10 * j + k - 14][k2];
											mink2 = k2;
										}
									}
								}
								if (mink2 != -1)
								{
									dp[i][j][k] = mi + k * pow10;
								}
							}
						}
					}
					else
					{
						int k = note[note.size() - i] - '0';
						for (int j = 0; j <= 1; ++j)
						{
							int mink2 = -1;
							long long mi = 1e18;
							for (int k2 = 0; k2 < 10; ++k2)
							{
								if ((10 * j + k == 1 || 10 * j + k == 0) && i > l1)
								{
									if (dp[i - 1][10 * j + k][k2] != -1 && dp[i - 1][10 * j + k][k2] < mi)
									{
										mi = dp[i - 1][10 * j + k][k2];
										mink2 = k2;
									}
								}
								if ((10 * j + k - 4 == 1 || 10 * j + k - 4 == 0) && i > l2 && i <= l1)
								{
									if (dp[i - 1][10 * j + k - 4][k2] != -1 && dp[i - 1][10 * j + k - 4][k2] < mi)
									{
										mi = dp[i - 1][10 * j + k - 4][k2];
										mink2 = k2;
									}
								}
								if ((10 * j + k - 7 == 1 || 10 * j + k - 7 == 0) && i > l2 && i <= l1)
								{
									if (dp[i - 1][10 * j + k - 7][k2] != -1 && dp[i - 1][10 * j + k - 7][k2] < mi)
									{
										mi = dp[i - 1][10 * j + k - 7][k2];
										mink2 = k2;
									}
								}
								if ((10 * j + k - 8 == 1 || 10 * j + k - 8 == 0) && i <= l2)
								{
									if (dp[i - 1][10 * j + k - 8][k2] != -1 && dp[i - 1][10 * j + k - 8][k2] < mi)
									{
										mi = dp[i - 1][10 * j + k - 8][k2];
										mink2 = k2;
									}
								}
								if ((10 * j + k - 11 == 1 || 10 * j + k - 11 == 0) && i <= l2)
								{
									if (dp[i - 1][10 * j + k - 11][k2] != -1 && dp[i - 1][10 * j + k - 11][k2] < mi)
									{
										mi = dp[i - 1][10 * j + k - 11][k2];
										mink2 = k2;
									}
								}
								if ((10 * j + k - 14 == 1 || 10 * j + k - 14 == 0) && i <= l2)
								{
									if (dp[i - 1][10 * j + k - 14][k2] != -1 && dp[i - 1][10 * j + k - 14][k2] < mi)
									{
										mi = dp[i - 1][10 * j + k - 14][k2];
										mink2 = k2;
									}
								}
							}
							if (mink2 != -1)
							{
								dp[i][j][k] = mi + k * pow10;
							}
						}
					}
					pow10 *= 10;
				}
				for (int i = 1; i < 10; ++i)
				{
					if (dp[note.size()][0][i] != -1)
					{
						if (ans == -1 || (ans != -1 && ans > dp[note.size()][0][i]))
						{
							ans = dp[note.size()][0][i];
						}
					}
				}
			}
		}
		
		return ans;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "?"; long long Arg1 = 8LL; verify_case(0, Arg1, construct(Arg0)); }
	void test_case_1() { string Arg0 = "?1"; long long Arg1 = 11LL; verify_case(1, Arg1, construct(Arg0)); }
	void test_case_2() { string Arg0 = "4?8"; long long Arg1 = 448LL; verify_case(2, Arg1, construct(Arg0)); }
	void test_case_3() { string Arg0 = "2??"; long long Arg1 = -1LL; verify_case(3, Arg1, construct(Arg0)); }
	void test_case_4() { string Arg0 = "??????????????"; long long Arg1 = 11888888888888LL; verify_case(4, Arg1, construct(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
	LuckySum ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
