#ifndef _MY_STRING_H_

#define _MY_STRING_H_
 
int find_sr(FILE *f, float *s);
void find_dispersion(FILE *f, float sr, double *disp);
int check_three_sigma(FILE *f, double disp, float sr, double k);

#endif