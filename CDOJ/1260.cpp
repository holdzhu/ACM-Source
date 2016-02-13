#include <stdio.h>
int x[]={-3,0,1,-1,-1,3,-4,1,6},n,m,i;main(){scanf("%d%d",&n,&m);while(n>=m*2&&n<=m*7&&m--){for(i=8;(n-=x[i--])<m*2||n>m*7;);putchar(i+50);}puts(n?"-1":"");}
