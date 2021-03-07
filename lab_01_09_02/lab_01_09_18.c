#include <stdio.h>
#include <math.h>
int mult(double *sum)
{
	int n = 0, checker;
	double curr;
	checker = scanf("%lf", &curr);
	if (checker != 1)
		return 1;
	if (curr < 0)
		return 2;
	while (curr >= 0)
	{
		n += 1;
		*sum += sqrt(n + curr);
		scanf("%lf", &curr);
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