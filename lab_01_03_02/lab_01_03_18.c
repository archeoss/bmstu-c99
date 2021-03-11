#include <stdio.h>
int print_resistance(float r1, float r2, float r3)
{
	r = r1 * r2 * r3 / (r1 * r2 + r3 * r2 + r1 * r3);
	printf("The resistance of system: %f", r);
	return 0;	
}
int main()
{
	float r1, r2, r3, r;
	printf("Input resistance of resistors:\n ");
	scanf("%f%f%f", &r1, &r2, &r3);
	print_resistance(r1, r2, r3)
	return 0;
} 