
 #include <stdio.h>
 #include <omp.h>
 
 #define N 20
 
 int main(){
 
 int sum = 0;
 int a[N],i;
 
#pragma omp parallel for schedule(dynamic,2)
   for(i=0;i<N;i++){
     a[i] = i;
     printf(" iterate i=%3d by thread %3d\n",i,omp_get_thread_num());
   }
 
 return 0;
 
 }
