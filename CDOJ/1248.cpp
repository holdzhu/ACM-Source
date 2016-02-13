#include <cstdio>

const int maxn = 1e5;

int n, K, Z;
int p[maxn];
int msk[maxn];
int dp[maxn + 2][1 << 8];
int id[maxn + 2];
int t[2] = {0, maxn + 1};

void push(int j, int &t0, int t1)
{
	for (int k = 0; k < 1 << K; ++k)
	{
		dp[t1][k] = dp[t0][k];
		if ((k & msk[j]) == msk[j] && dp[t1][k ^ msk[j]] + p[j] > dp[t1][k])
		{
			dp[t1][k] = dp[t1][k ^ msk[j]] + p[j];
			if (dp[t1][k] > Z)
				dp[t1][k] = Z;
		}
	}
	id[t0 = t1] = j;
}

void pop()
{
	if (t[0])
		t[0]--;
	else
		while (++t[1] <= maxn)
			push(id[t[1] - 1], t[0], t[0] + 1);
}

bool check()
{
	for (int i = 0; i < 1 << K; ++i)
		if (dp[t[0]][i] + dp[t[1]][~i & ((1 << K) - 1)] >= Z)
			return true;
	return false;
}
#define BUF_SIZE 100000
#define OUT_SIZE 100000

inline char nc(){
	static char buf[BUF_SIZE],*p1=buf+BUF_SIZE,*pend=buf+BUF_SIZE;
	if (p1==pend){
	p1=buf; pend=buf+fread(buf,1,BUF_SIZE,stdin);
	}
	return *p1++;
}
inline bool blank(char ch){return ch==' '||ch=='\n'||ch=='\r'||ch=='\t';}

inline void read(int &x){
	bool sign=0; char ch=nc(); x=0;
	for (;blank(ch);ch=nc());
	if (ch=='-')sign=1,ch=nc();
	for (;ch>='0'&&ch<='9';ch=nc())x=x*10+ch-'0';
	if (sign)x=-x;
}

char buf[BUF_SIZE];
char *p1=buf,*pend=buf+BUF_SIZE;

void out(char ch){
	if (p1==pend){
	    fwrite(buf,1,BUF_SIZE,stdout);p1=buf;
	}
	*p1++=ch;
}
void println(int x){
	static char s[15],*s1;s1=s;
	if (!x)*s1++='0';if (x<0)out('-'),x=-x;
	while(x)*s1++=x%10+'0',x/=10;
	while(s1--!=s)out(*s1); out('\n');
}

int main()
{
	read(n);
	read(K);
	read(Z);
	for (int i = 0; i < n; ++i)
		read(p[i]);
	for (int i = 0; i < n; ++i)
	{
		int k;
		read(k);
		while (k--)
		{
			int x;
			read(x);
			msk[i] |= 1 << (x - 1);
		}
	}
	int i, j;
	for (i = 0, j = 0; i < n; ++i)
	{
		bool flag = check();
		while (j < n && !flag)
		{
			push(j++, t[1], t[1] - 1);
			flag = check();
		}
		if (!flag)
			break;
		println(j);
		pop();
	}
	if (p1!=buf)
	{
		fwrite(buf,1,p1-buf,stdout);
		p1=buf;
	}
	for (; i < n; ++i)
		puts("-1");
	return 0;
}