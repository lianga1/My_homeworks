#include<stdio.h>
#include<math.h>
int main()
{
	float x,sine,cosine,ans;
	const float pi=3.14;
	scanf("%f",&x);
	sine = sin(x)/x;
	cosine = cos(pi*x/2);
	if (cosine<0)
		cosine = -cosine;
	ans = sine + cosine ;
	printf("%f",ans);
	return 0;
}
