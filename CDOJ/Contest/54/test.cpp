#include <cstdio>
#include <algorithm>

using namespace std;

#define MAXN 1100

int n;

struct node
{
    int v,a;
    bool operator<(const node &a) const{
        return v<a.v;
    }
}jobs[MAXN];

void Init()
{
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
        scanf("%d%d",&jobs[i].v,&jobs[i].a);
    sort(jobs+1,jobs+1+n);
}

void Work()
{
    int i,j,mid,l,r;
    for(l=0,r=jobs[n].v;l<r;i<=n?l=mid+1:r=mid){
        mid=(l+r)>>1;
        for(i=1,j=mid;i<=n;++i){
            if(j>=jobs[i].v) j+=jobs[i].a;
            else break;
        }
    }
    printf("%d\n",r);
}

int main()
{
    Init();
    Work();
    return 0;
}