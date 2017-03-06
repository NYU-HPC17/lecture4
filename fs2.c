#include <stdio.h>
#include <math.h>
#include <omp.h>

#define N 100000

int main()
{
   int num_threads = omp_get_max_threads();
   double sum=0.0, sum_local[num_threads];
   double x[N], y[N];
   int i;

   for (i = 0; i < N; i++){
     x[i] = i*i;
     y[i] = sin(x[i]);
   }
          
#pragma omp parallel num_threads(num_threads) reduction(+:sum)
  {
   int me = omp_get_thread_num();
   
   #pragma omp for
   for (i = 0; i < N; i++)
   sum += x[i] * y[i];
   
  }

  printf("Final sum = %25.15e using %d threads\n",sum, num_threads);

}


