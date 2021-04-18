#include <stdio.h>

float count_resistance(float, float, float);

int main()
{
	float r1, r2, r3;
	printf("Input resistance of resistors:\n ");
	scanf("%f%f%f", &r1, &r2, &r3);
	float r = count_resistance(r1, r2, r3);
	printf("The resistance of system: %f", r);
	return 0;
} 

float count_resistance(float r1, float r2, float r3)
{
	return r1 * r2 * r3 / (r1 * r2 + r3 * r2 + r1 * r3);	
}