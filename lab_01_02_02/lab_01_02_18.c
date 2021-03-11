#include <stdio.h>
#include <math.h>
double get_length(double x1, double x2, double y1, double y2)
{
	double a = sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2));
	return a;
}	
int main()
{
	double x1, y1, x2, y2, x3, y3, a, b, c, p;
	printf("Input coords of tringle:\n");
	scanf("%lf%lf%lf%lf%lf%lf", &x1, &y1, &x2, &y2, &x3, &y3);
	a = get_length(x1, x2, y1, y2);
	b = get_length(x1, x3, y1, y3);
	c = get_length(x3, x2, y3, y2);
	p = a + b + c;
	printf("The perimmetr of triangle: %lf", p);
	return 0;
} 