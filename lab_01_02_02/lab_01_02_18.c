#include <stdio.h>
#include <math.h>

double perimetr (double, double, double, double, double, double);
double get_length(double, double, double, double);

int main()
{
	double x1, y1, x2, y2, x3, y3, p;
	printf("Input coords of tringle:\n");
	scanf("%lf%lf%lf%lf%lf%lf", &x1, &y1, &x2, &y2, &x3, &y3);
	p = perimetr(x1, y1, x2, y2, x3, y3);
	printf("The perimetr of triangle: %lf", p);
	return 0;
} 

double perimetr(double x1, double y1, double x2, double y2, double x3, double y3)
{
	double p = get_length(x1, x2, y1, y2) + get_length(x1, x3, y1, y3) + get_length(x3, x2, y3, y2);
	return p;
}

double get_length(double x1, double x2, double y1, double y2)
{
	double a = sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2));
	return a;
}	