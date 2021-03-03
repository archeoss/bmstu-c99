#include <stdio.h>
int main()
{
	int seconds, minutes, hours;
	printf("Input seconds:\n ");
	scanf("%d", &seconds);
	hours = seconds / 3600;
	seconds = seconds % 3600;
	minutes = seconds / 60;
	seconds = seconds % 60;
	printf("Time: %d %d %d", hours, minutes, seconds);
	return 0;
} 