#include <stdio.h>
int find_pos_after_neg(FILE *f)
{
	int max_n = -1, flag = 0;
	int i = 0, rc;
	while ((rc = fscanf(f, "%d ", &i)) != EOF && rc == 1)
	{
		if (i < 0)
			flag = 1;
		else if (flag == 1)
		{
			if (max_n < i)
				max_n = i;
			flag = 0;
		}
	}
	return max_n;
}