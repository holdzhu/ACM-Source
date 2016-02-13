

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <cmath>
#include <iostream>
#include <cstdlib>
#include <sstream>
#include <ctime>
using namespace std;

const int M=(int)1e9+7;
const int maxn=10000001;

void add(int &a,int b)
{
	a+=b;
	if(a>=M)a-=M;
}
bool vis[maxn];
int prime[maxn/10],phi[maxn][5],u[maxn],pcnt;
int dp[1010];
int a[10][10]={
	{
		2,1,1
	},
	{
		6,1,3,2
	},
	{
		4,0,1,2,1
	},
	{
		30,M-1,0,10,15,6
	},
	{
		12,0,M-1,0,5,6,2
	}
};
int inv[100];

long long N,K;

int F(int x)
{
	int xx=x;
	int ans=0;
	for(int i=1;i<=K+2;i++)
	{
		add(ans,1LL*x*a[K][i]%M);
		x=1LL*x*xx%M;
	}
	return 1LL*ans*inv[a[K][0]]%M;
}

int U(long long xx)
{
	long long n=N/xx;
	if(n<maxn)return u[n];
	int& ans=dp[xx];
	if(ans)return ans;
	for(long long i=2;i<=n;i++)
	{
		long long x=n/i;
		long long nx=n/x;
		add(ans,(nx-i+1)%M*U(i*xx)%M);
		i=nx;
	}
	ans=(1-ans+M)%M;
	return ans;
}

int PHI(long long xx)
{
	long long n=N/xx;
	if(n<maxn)return phi[n][K];
	int ans=0;
	int pre=0;
	for(long long i=1;i<=n;i++)
	{
		long long x=n/i;
		long long nx=n/x;
		if(x>=M)x%=M;
		int t=U(x*xx);
		add(ans,1LL*F(x)*(t-pre+M)%M);
		pre=t;
		i=nx;
	}
	return ans;
}

int SUM()
{
	int ans=0;
	int pre=0;
	for(long long i=1;i<=N;i++)
	{
		long long x=N/i;
		long long nx=N/x;
		if(x>=M)x%=M;
		int t=PHI(x);
		add(ans,x*x%M*(t-pre+M)%M);
		pre=t;
		i=nx;
	}
	return ans;
}

int Pow(int n,int p)
{
	int ans=1;
	while(p--)ans=1LL*ans*n%M;
	return ans;
}

int bf()
{
	int ans=0;
	for(int i=1;i<=N;i++)
		for(int j=1;j<=N;j++)
			add(ans,Pow(__gcd(i,j),K+1));
	return ans;
}
int main()
{
	u[1]=1;for(int i=0;i<5;i++)phi[1][i]=1;
	for(int i=2;i<maxn;i++)
	{
		if(!vis[i])
		{
			prime[++pcnt]=i;
			u[i]=-1;
			long long x=i;
			for(int k=0;k<5;k++)
			{
				phi[i][k]=x-1;
				x=x*i%M;
			}
		}
		for(int j=1;j<=pcnt&&i*prime[j]<maxn;j++)
		{
			vis[i*prime[j]]=1;
			if(i%prime[j]==0)
			{
				long long x=prime[j];
				for(int k=0;k<5;k++)
				{
					phi[i*prime[j]][k]=phi[i][k]*x%M;
					x=x*prime[j]%M;
				}
				break;
			}
			else
			{
				for(int k=0;k<5;k++)
				{
					phi[i*prime[j]][k]=1LL*phi[i][k]*phi[prime[j]][k]%M;
				}
				u[i*prime[j]]=-u[i];
			}
		}
	}
	for(int i=2;i<maxn;i++)
	{
		add(u[i],u[i-1]+M);
		for(int j=0;j<5;j++)
			add(phi[i][j],phi[i-1][j]);
	}
	inv[0]=inv[1]=1;
	for(int i=2;i<100;i++)inv[i]=(M-1LL*(M/i)*inv[M%i]%M)%M;

	for(int cas=1;cas<=1;cas++)
	{
//		char in[111],out[111];
//		sprintf(in,"%03d.in",cas);
//		sprintf(out,"%03d.out",cas);
//		freopen(in,"r",stdin);
//		freopen(out,"w",stdout);
		cin>>N>>K;
		K--;
		memset(dp,0,sizeof(dp));
		cout<<SUM()<<endl;
	}
	return 0;
}

