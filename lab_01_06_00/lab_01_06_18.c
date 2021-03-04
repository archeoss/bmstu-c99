#include <stdio.h>
#include <math.h>
float max_min(float a, float b)
{
	if (a > b)
		return a, b;
	else
		return b, a;
}
float triangle(float a, float b, float c)
{	
	int result;
	float temp;
	float max_l = a;
	float min_l_one = b, min_l_two = c;
	a, b = max_min(a, b);
	a, c = max_min(a, c);
	if (a*a == b*b + c*c)
		result = 1;
	else if (a*a < b*b + c*c)
		result = 0;
	else 
		result = 2;
	return result;
}
int main()
{
	float x1, y1, x2, y2, x3, y3, a, b, c;
	int result, error_code, rc;
	printf("Input coords of tringle:\n");
	rc = scanf("%f%f%f%f%f%f", &x1, &y1, &x2, &y2, &x3, &y3); 
	if (rc == 6)
		error_code = 0;
	else 
		error_code = 1;
	if (error_code == 0)
	{
		a = sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2));
		b = sqrt(pow((x1 - x3), 2) + pow((y1 - y3), 2));
		c = sqrt(pow((x3 - x2), 2) + pow((y3 - y2), 2));
		if (a == 0) and (b == 0)
		{
			result = triangle(a, b, c);
			printf("%d", result);
		}
		else
		{
			printf("Input Error");
			error_code = 2;
		}
	}
	else
		printf("Input Error");
	return error_code;
} 