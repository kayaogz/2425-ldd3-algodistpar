#include <cstdio>
#include <vector>
#include "omp.h"
#include "unistd.h"

int main()
{
  int N = 100;
  std::vector<int> A(N);

//  for (int i = 0; i < N; i++) { A[i] = i; }

#pragma omp parallel num_threads(4)
  {
    int thid = omp_get_thread_num();
    int numth = omp_get_num_threads();

#pragma omp for
    for (int i = 0; i < N; i++) { printf("i = %d, thid = %d\n", i, thid); A[i] = i; }

//    int niter = N / numth;
//    int debut = ...;
//    int fin = ...;
//    for (int i = debut; i < fin; i++) { A[i] = i; }
//
//#pragma omp sections
//    {
//#pragma omp section
//      {
//        printf("hello thid=%d\n", thid);
//        for (int i = 0; i < N / 4; i++) { A[i] = i; }
//      }
//#pragma omp section
//      {
//        printf("hello thid=%d\n", thid);
//        for (int i = N / 4; i < 2 * N / 4; i++) { A[i] = i; }
//      }
//#pragma omp section
//      {
//        printf("hello thid=%d\n", thid);
//        for (int i = 2 * N / 4; i < 3 * N / 4; i++) { A[i] = i; }
//      }
//#pragma omp section
//      {
//        printf("hello thid=%d\n", thid);
//        for (int i = 3 * N / 4; i < N; i++) { A[i] = i; }
//      }
//    }
  }

  for (int i = 0; i < N; i++) { printf("A[%d] = %d\n", i, A[i]); }
  return 0;
}
/*











#pragma omp parallel num_threads(11)
  {
    int thid = omp_get_thread_num();
    int numth = omp_get_num_threads();

//#pragma omp sections
//    {
//#pragma omp section
//      {
//        printf("hello thid=%d\n", thid);
//        for (int i = 0; i < N / 2; i++) { A[i] = i; }
//      }
//#pragma omp section
//      {
//        printf("hello thid=%d\n", thid);
//        for (int i = N / 2; i < N; i++) { A[i] = i; }
//      }
//    }
  }

  for (int i = 0; i < N; i++) { printf("%d ", A[i]); }
  printf("\n");

  return 0;
}
*/
