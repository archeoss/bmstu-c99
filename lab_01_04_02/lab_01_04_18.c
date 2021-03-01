#include <stdio.h>
int main()
{
	int secs, minutes, hours;
	printf("Input seconds:\n ");
	scanf("%f", &seconds);
	hours = seconds / 3600;
	seconds = seconds % 3600;
	minutes = seconds / 60;
	seconds = seconds % 60;
	printf("Time: %f:%f:%f", hours, minutes, seconds);
	return 0;
} 