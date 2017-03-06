#include <stdio.h>
#include <omp.h>
#include <math.h>


int main(){

   int i;

   #pragma omp parallel  for
     for (i='a';i<='z';i++) {
       printf("     %c   thread %d\n",i,omp_get_thread_num());
     }

   return 0;
}
