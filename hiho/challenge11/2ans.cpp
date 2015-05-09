#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

int n,i,j,k;
int a[100005],b[100005];
int p[100005],prime[100005],tot;
long long ans,tmp;

long long calc(int x,int y)
{
	long long z=1;
	int c,v;
	for(;x>1||y>1;)
	{
		if(p[x]<p[y])c=p[x];else c=p[y];
		v=1;
		for(;p[x]==c;x/=c)++v;
		for(;p[y]==c;y/=c)++v;
		z*=v;
	}
	return z;
}

inline bool cmp(const int &x,const int &y){return b[x]>b[y];}

int main()
{
	n=100000;
	for(i=2;i<=n;++i)
	{
		if(!p[i])prime[++tot]=p[i]=i;
		for(j=1;j<=tot&&prime[j]<=p[i]&&prime[j]<=n/i;++j)p[i*prime[j]]=prime[j];
	}
	p[1]=1000000;
	for(i=1;i<=n;++i)b[i]=calc(i,1);
for (int i = 0; i < 100; ++i)
{
	printf("%d %d %d %d\n", i, p[i], prime[i], b[i]);
}
	scanf("%d",&n);
	for(i=1;i<=n;++i)scanf("%d",&a[i]);
	sort(a+1,a+n+1,cmp);
	ans=b[a[1]];
	for(i=1;i<=n;++i)
	for(j=i;j<=n;++j)
	if((long long)b[a[i]]*b[a[j]]>ans)
	{
		tmp=calc(a[i],a[j]);
		if(tmp>ans)ans=tmp;
	}
	else break;
	printf("%lld\n",ans);
}