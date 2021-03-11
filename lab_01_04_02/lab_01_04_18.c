#include <stdio.h>
int print_correct_time(int seconds)
{	
	int hours = seconds / 3600;
	seconds = seconds % 3600; 
	int minutes = seconds / 60;
	seconds = seconds % 60;
	printf("Time: %d %d %d", hours, minutes, seconds);
	return 0;
}
int main()
{
	int seconds;
	printf("Input seconds:\n ");
	scanf("%d", &seconds);
	print_correct_time(seconds);
	return 0;
} 