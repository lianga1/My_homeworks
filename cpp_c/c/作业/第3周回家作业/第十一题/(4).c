#include <stdio.h>

int main()
{
	float M1,M2,R,F;
	scanf("%f %f %f",&M1,&M2,&R);
	const double G = 6.67e-10;
	F = G*M1*M2/(R*R);
	printf("%f",F);
	
	return 0;
}
