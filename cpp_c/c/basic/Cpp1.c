#include<stdio.h>
#include<math.h>
int main()
{
    double x=0.0;
    double cosx=0;
    int symbol=1;
    int k,i,j,N=100;
	int fac;
    printf("please enter the x ");
    scanf("%lf",&x);
    for(i=0;i<=N;i++)
 {
        k=2*i;
		fac=1;
        for(j=k;j>=1;j--)
  {
        fac*=j;
  }
        if(fac>=100000) break;
        cosx+=(double) pow(x,k)*symbol/fac;
        symbol*=-1;
 }
    printf("%lf",cosx);
    return 0;
}