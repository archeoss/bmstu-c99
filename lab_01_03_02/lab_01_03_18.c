#include <stdio.h>
int main()
{
	int r1, r2, r3;
	float r;
	printf("Input resistance of 3 resistors:\n ");
	scanf("%d%d%d", &r1, &r2, &r3);
	r = r1 * r2 * r3 / (r1 * r2 + r3 * r2 + r1 * r3);
	printf("The resistance of system: %f", r);
	return 0;
} 