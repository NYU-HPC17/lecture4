

 #include <omp.h>
 #include <stdio.h>
 #include <stdlib.h>

int main(int argc, char *argv[]) {

  int nThreads;

  if (argc != 2){
    printf("Must enter integer for number threads on command line\n");
    fflush(stdout);
    exit(-1);
  }
  else {  
    nThreads = atoi(argv[1]);
    printf("Using %d threads\n",nThreads);
  }
  
#pragma omp parallel num_threads(nThreads)
  {
    printf("Hello world from thread %d of %d\n",
            omp_get_thread_num(),omp_get_num_threads());
  }

 return 0;
}
