#include<stdio.h>
#include<math.h>
#define f(X,i,s)for(i=X;i--;)s*(2*(i+1)*(X-i)-1)/X/X
double a,b;int X,Y,Z,K,i,j,k;int main(){scanf("%d%d%d%d",&X,&Y,&Z,&K);f(X,i,f(Y,j,f(Z,k,b=1-2.))),a+=1-pow(b,K);printf("%.9f\n",a/2);}