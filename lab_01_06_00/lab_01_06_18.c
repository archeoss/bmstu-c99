#include <stdio.h>
#include <math.h>
float triangle(int a, int b, int c)
{	
	int result, temp
	printf("%f%f%f", a, b, c);
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
	printf("%f%f%f", a, b, c);
	if (a * a == b * b + c * c)
		result = 1;
	else if (a * a < b * b + c * c)
		result = 0;
	else 
		result = 2;
	return result;
}
int main()
{
	int x1, y1, x2, y2, x3, y3, a, b, c;
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
		if (a * b * c != 0)
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