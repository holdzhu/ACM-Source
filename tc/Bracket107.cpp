#line 7 "Bracket107.cpp"
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


class Bracket107
{
	public:
	int yetanother(string s)
	{
		int n = s.size();
		set<long long> se;
		for (int i = 0; i < n; ++i)
		{
			if (s[i] == '(')
			{
				string t;
				for (int j = 0; j < n; ++j)
				{
					if (j != i)
					{
						t += s[j];
					}
				}
				for (int j = 0; j < n; ++j)
				{
					int cnt = 0;
					long long hsh = 0;
					bool flag = true;
					for (int k = 0; k < n; ++k)
					{
						if (j == k)
						{
							cnt++;
							hsh <<= 1ll;
							hsh |= 1ll;
						}
						if (k < n - 1)
						{
							if (t[k] == '(')
							{
								cnt++;
								hsh <<= 1ll;
								hsh |= 1ll;
							}
							else
							{
								cnt--;
								hsh <<= 1ll;
								if (cnt < 0)
								{
									flag = false;
									break;
								}
							}
						}
					}
					if (flag)
					{
						se.insert(hsh);
					}
				}
			}
			else
			{
				string t;
				for (int j = 0; j < n; ++j)
				{
					if (j != i)
					{
						t += s[j];
					}
				}
				for (int j = 0; j < n; ++j)
				{
					int cnt = 0;
					long long hsh = 0;
					bool flag = true;
					for (int k = 0; k < n; ++k)
					{
						if (j == k)
						{
							cnt--;
							hsh <<= 1ll;
							if (cnt < 0)
							{
								flag = false;
								break;
							}
						}
						if (k < n - 1)
						{
							if (t[k] == '(')
							{
								cnt++;
								hsh <<= 1ll;
								hsh |= 1ll;
							}
							else
							{
								cnt--;
								hsh <<= 1ll;
								if (cnt < 0)
								{
									flag = false;
									break;
								}
							}
						}
					}
					if (flag)
					{
						se.insert(hsh);
					}
				}
			}
		}
		return se.size() - 1;
	}
	

};



// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
