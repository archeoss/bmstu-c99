#include <stdio.h>
#include <stdlib.h>
#define N 255

int load_and_print(char *f, char *f_out);

struct Mark
{
	char subject[N];
	int mark;
};
struct Student
{
	char name[N];
	char surname[N];
	char group[N];
	struct Mark marks[5];
};
int main(void)
{
	char file_in[N];
	char file_out[N] = "output.txt";
	
	scanf("%s", &file_in);
	load_and_print(file_in,file_out);
	return 0;
}

int load_and_print(char *f, char *f_out)
{
	FILE *fp = fopen(f,"r");
	FILE *fo = fopen(f_out,"w");
	struct Student std[N];
	int i = 0;
	char j = 0;
	while (fscanf(fp, "%s%s%s", std[i].name,&(std[i].surname),&(std[i].group)) != EOF)
	{
		for (int j = 0; j < 5; j++)
		{
			fscanf(fp,"%s%d",std[i].marks[j].subject,&(std[i].marks[j].mark));
			
		}
		i++;
	}
	printf("%d",i);
	fclose(fp);
	for (int k = 0; k < i; k++)
	{
		fprintf(fo,"%s %s %s",std[k].name, std[k].surname, std[k].group);
		for (int j = 0; j < 5; j++)
		{ 
			fprintf(fo,"%s %d ",std[k].marks[j].subject,std[k].marks[j].mark);
		}
		fprintf(fo,"/n");
	}
	fclose(fo);	
	return 0;
}