
  #include <stdio.h>
  #include <omp.h>
  
  int main(){
  
    int x = 2;

#pragma omp parallel shared(x) num_threads(2)
    {
      if (1 == omp_get_thread_num()){
        x = 5;
      }
      else {
        printf("1: Thread %d has x = %d\n",omp_get_thread_num(),x);
      }
  
      #pragma omp barrier
  
      if (0 == omp_get_thread_num()) {
        printf("2: thread %d has x = %d\n",omp_get_thread_num(),x);
      }
      else {
        printf("3: thread %d has x = %x\n",omp_get_thread_num(),x);
      }
  
    }
    return 0;
  }


