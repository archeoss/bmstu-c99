#include <stdio.h>
#include <math.h>
int mult(double *sum)
{
	int n = 0, err_code;
	double x;
	err_code = scanf("%lf", &x);
	if (err_code != 1)
		return 1;
	if (x < 0)
		return 2;
	while (x >= 0)
	{
		n += 1;
		*sum += sqrt(n + x);
		scanf("%lf", &x);
	}
	*sum /= n;
	return 0;
}
int main()
{
	double sum = 0;
	int error_code;
	error_code = mult(&sum);
	if (error_code == 0)
	{
		printf("%.6lf", sum);
	}
	return error_code;
}