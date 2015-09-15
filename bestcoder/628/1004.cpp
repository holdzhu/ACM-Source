#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
#include <vector>

using namespace std;

char s[100010];
long long ss[100010];

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%s", s);
		int n = strlen(s);
		for (int i = 0; i < n; ++i)
		{
			s[i] -= 'A';
		}
		int t;
		scanf("%d", &t);
		int l = 0;
		long long sum = 0;
		while (sum < 1e11)
		{
			l++;
			if (l == n + 1)
			{
				break;
			}
			sum += (1LL << l);
			vector<long long> st;
			long long last = 0;
			for (int i = 0; i < l; ++i)
			{
				last = last * 2 + s[i];
			}
			st.push_back(last);
			for (int i = 0; i < n - l; ++i)
			{
				last = last << 1;
				last &= (1LL << l) - 1;
				last = last + s[i + l];
				st.push_back(last);
			}
			sort(st.begin(), st.end());
			st.erase(unique(st.begin(), st.end()), st.end());
			sum -= st.size();
			ss[l] = sum;
		}
		while (t--)
		{
			int K;
			scanf("%d", &K);
			int l = 0;
			ss[0] = 0;
			while (ss[l] < K)
			{
				l++;
				if (l == n + 1)
				{
					break;
				}
			}
			if (l == n + 1)
			{
				sum = ss[n];
				while (sum + (1LL << l) < K)
				{
					sum += (1LL << l);
					l++;
				}
				long long ans = K - sum - 1;
				for (int i = l - 1; i >= 0; --i)
				{
					putchar((!!(ans & (1LL << i))) + 'A');
				}
				puts("");
			}
			else
			{
				long long lastsum = ss[l - 1];
				vector<long long> st;
				long long last = 0;
				for (int i = 0; i < l; ++i)
				{
					last = last * 2 + s[i];
				}
				st.push_back(last);
				for (int i = 0; i < n - l; ++i)
				{
					last = last << 1;
					last &= (1LL << l) - 1;
					last = last + s[i + l];
					st.push_back(last);
				}
				st.push_back(1LL << l);
				sort(st.begin(), st.end());
				st.erase(unique(st.begin(), st.end()), st.end());
				long long ans = -1;
				for (int i = 0; i < st.size(); ++i)
				{
					if (lastsum + st[i] - i >= K)
					{
						ans = K - lastsum + i - 1;
						break;
					}
				}
				for (int i = l - 1; i >= 0; --i)
				{
					putchar((!!(ans & (1LL << i))) + 'A');
				}
				puts("");
			}
		}
	}
	return 0;
}
