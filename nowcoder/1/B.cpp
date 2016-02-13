#include <cstdio>
#include <string>
#include <vector>

using namespace std;

const unsigned int H = 107;
const unsigned int H2 = 113;

class SeparateWords {
	unsigned long long p[101];
	unsigned long long w[1000];
	unsigned long long l[101];
	unsigned long long p2[101];
	unsigned long long w2[1000];
	unsigned long long l2[101];
public:
    int getMaxSegs(string S, vector<string> dics, int n) {
        p[0] = p2[0] = 1;
        for (int i = 0; i < 100; ++i)
        {
        	p[i + 1] = p[i] * H;
        	l[i + 1] = 0;
        	p2[i + 1] = p2[i] * H2;
        	l2[i + 1] = 0;
        }
        for (int i = 0; i < n; ++i)
        {
        	w[i] = 0;
        	w2[i] = 0;
        	for (int j = 0; j < dics[i].length(); ++j)
        	{
        		w[i] *= H;
        		w[i] += dics[i][j];
        		w2[i] *= H2;
        		w2[i] += dics[i][j];
        	}
        }
        int ans = 0;
        int last = -1;
        for (int i = 0; i < (int)S.length(); ++i)
        {
        	for (int j = 1; j <= 100; ++j)
        	{
        		l[j] *= H;
        		l[j] += S[i];
        		l2[j] *= H2;
        		l2[j] += S[i];
        		if (j <= i)
        		{
        			l[j] -= S[i - j] * p[j];
        			l2[j] -= S[i - j] * p2[j];
        		}
        	}
        	for (int j = 0; j < n; ++j)
        	{
        		if (i - (int)dics[j].length() >= last && l[(int)dics[j].length()] == w[j] && l2[(int)dics[j].length()] == w2[j])
        		{
        			last = i;
        			ans++;
        			break;
        		}
        	}
        }
        return max(ans, 1);
    }
};

int main()
{
	SeparateWords sw;
	printf("%d\n", sw.getMaxSegs("aabbccdd", {"aa","bb","c","d"}, 4));
	return 0;
}
