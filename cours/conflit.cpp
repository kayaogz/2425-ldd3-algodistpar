#include <cstdio>
#include <vector>
#include "omp.h"
#include "unistd.h"

int main()
{
  int N = 1000000;
  int k = 0;

#pragma omp parallel num_threads(4)
  {
    // methode 1
    //#pragma omp for
    //    for (int i = 0; i < N; i++) { 
    //  #pragma omp atomic
    //      k = k + 1;
    //
    // methode 2
    //  int klocal = 0;
    //#pragma omp for
    //    for (int i = 0; i < N; i++) { 
    //      klocal = klocal + 1;
    //    }
    //#pragma omp atomic
    //    k = k + klocal;
    //

    // methode 3
#pragma omp for reduction(+:k)
    for (int i = 0; i < N; i++) { 
      k = k + 1;
    }
  }

  printf("%d %d\n", k, N);
  return 0;
}
