#include <stdio.h>
#include <math.h>

#define NO_ERRORS 0
#define INPUT_ERROR -1
#define INCORRECT_DATA -2

#define RIGHT_TRIANGLE 1
#define ACUTE_ANGLED_TRIANGLE 0
#define OBTUSE_TRIANGLE 2

#define EPSILON 1e-5

double get_length(double, double, double, double);
int triangle(int *, double, double, double);

int main()
{
	double x1, y1, x2, y2, x3, y3, a, b, c;
	int result = -1, error_code, rc;
	printf("Input coords of tringle:\n");
	rc = scanf("%lf%lf%lf%lf%lf%lf", &x1, &y1, &x2, &y2, &x3, &y3); 
	if (rc == 6)
		error_code = NO_ERRORS;
	else 
		error_code = INPUT_ERROR;
	if (error_code == NO_ERRORS)
	{
		a = get_length(x1, x2, y1, y2);
		b = get_length(x1, x3, y1, y3);
		c = get_length(x3, x2, y3, y2);
		error_code = triangle(&result, a, b, c);
	}
	if (error_code == INCORRECT_DATA)
		printf("INCORRECT_DATA");
	else if (error_code == INPUT_ERROR)
		printf("INPUT_ERROR");
	else
		printf("%d", result);
	return error_code;
} 

double get_length(double x1, double x2, double y1, double y2)
{
	return sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2));
}	

int triangle(int *result, double a, double b, double c)
{	
	int error_code;
	double temp;
	if (a * b * c <= 0)
		error_code = INCORRECT_DATA;
	else if (a + b <= c || a + c <= b || c + b <= a)
		error_code = INCORRECT_DATA;
	else
	{
		if (b > a)
		{
			temp = a;
			a = b;
			b = temp;
		}
		if (c > a)
		{
			temp = a;
			a = c;
			c = temp;
		}
		if (a * a - EPSILON < b * b + c * c && a * a + EPSILON > b * b + c * c)
			*result = RIGHT_TRIANGLE;
		else if (a * a < b * b + c * c)
			*result = ACUTE_ANGLED_TRIANGLE;
		else 
			*result = OBTUSE_TRIANGLE;
		error_code = NO_ERRORS;
	}
	return error_code;
}