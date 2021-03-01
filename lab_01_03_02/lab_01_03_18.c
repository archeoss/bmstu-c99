#include <stdio.h>
int main()
{
	float R1,R2,R3,R;
	printf("Input resistance of 3 resistors:\n ");
	scanf("%f%f%f",&R1,&R2,&R3);
	R = 1/(1/R1+1/R2+1/R3);
	printf("The resistance of system: %f",R);
	return 0;
} 