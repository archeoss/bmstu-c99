#include <stdio.h>
int main()
{
	float r1, r2, r3, r;
	printf("Input resistance of 3 resistors:\n ");
	scanf("%f%f%f", &r1, &r2, &r3);
	r = 1 / (1 / r1 + 1 / r2 + 1 / r3);
	printf("The resistance of system: %f", r);
	return 0;
} 