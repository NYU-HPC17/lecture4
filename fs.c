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
          
#pragma omp parallel num_threads(num_threads)
  {
   int me = omp_get_thread_num();
   sum_local[me] = 0.0;
   
   #pragma omp for
   for (i = 0; i < N; i++)
   sum_local[me] += x[i] * y[i];
   
   #pragma omp atomic
   sum += sum_local[me];
  }

  printf("Final sum = %25.15e using %d threads\n",sum, num_threads);

}


