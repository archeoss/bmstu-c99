#ifndef _MY_STRING_H_

#define _MY_STRING_H_
 
float find_sr(FILE *f);
double find_dispersion(FILE *f, float sr);
int check_three_sigma(FILE *f, double disp, float sr, double k);
#endif