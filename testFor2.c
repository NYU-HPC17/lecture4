
#include <stdio.h>
#include <stdlib.h>
#include "timing.h"
#include <omp.h>
#include <math.h>
  
 int main(int argc, char *argv[]) {
 
 int sum = 0;
 int  i,j;
 size_t n;
 timestamp_type time1, time2;

  if (argc != 2){
    printf("Must enter integer for array size on command line\n");
    exit(-1);
  }
  else {  
    n = atoi(argv[1]);
    printf("Using array size %ld \n",n);
  }
  
  double *x = (double *) malloc(sizeof(double) * n);
  if (!x) { perror("alloc x"); abort(); }
  double *y = (double *) malloc(sizeof(double) * n);
  if (!y) { perror("alloc y"); abort(); }
  double *z = (double *) malloc(sizeof(double) * n);
  if (!z) { perror("alloc z"); abort(); }


  for (i=0;i<n;i++){
    x[i] = i;
    y[i] = 2*i;
  }


 get_timestamp(&time1);

#pragma omp parallel for 
   for(i=0;i<n;i++){
     z[i] = x[i] + y[i];
   }

  get_timestamp(&time2);
  double elapsed = timestamp_diff_in_seconds(time1,time2);
  printf("%f s\n", elapsed);

 return 0;
 
 }
