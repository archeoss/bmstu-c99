#include <stdio.h>

int get_correct_time(int *, int *, int *);

int main()
{
	int hours, minutes, seconds;
	printf("Input seconds:\n ");
	scanf("%d", &seconds);
	get_correct_time(&hours, &minutes, &seconds);
	printf("Time: %d %d %d", hours, minutes, seconds);
	return 0;
} 

int get_correct_time(int *hours, int *minutes, int *seconds)
{	
	*hours = *seconds / 3600;
	*seconds = *seconds % 3600; 
	*minutes = *seconds / 60;
	*seconds = *seconds % 60;
	return 0;
}
