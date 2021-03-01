#include <stdio.h>
#include <math.h>
int main()
{
	float x1, y1, x2, y2, x3, y3, a, b, c, p;
	printf("Input coords of tringle:\n");
	scanf("%f%f%f%f%f%f", &x1, &y1, &x2, &y2, &x3, &y3);
	a = sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2));
	b = sqrt(pow((x1 - x3), 2) + pow((y1 - y3), 2));
	c = sqrt(pow((x3 - x2), 2) + pow((y3 - y2), 2));
	p = a + b + c;
	printf("The perimmetr of triangle: %f", p);
	return 0;
} 