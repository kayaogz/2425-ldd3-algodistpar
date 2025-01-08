#include <cstdio>
#include "unistd.h"
#include "omp.h"

int calcul2()
{
  sleep(2);
  return 2;
}

int calcul3()
{
  sleep(3);
  return 3;
}

int calcul4()
{
  sleep(4);
  return 4;
}

int main()
{
  int deux = 0, trois = 0, quatre = 0, neuf = 0;

#pragma omp parallel num_threads(1)
  {
    int thid = omp_get_thread_num();
    printf("thid = %d\n", thid);
//    if (thid == 0) 
//      deux = calcul2();
//    else if (thid == 1)
//      trois = calcul3();
//    else if (thid == 2)
//      quatre = calcul4();
#pragma omp sections
    {
#pragma omp section
      {
        deux = calcul2();
      }
#pragma omp section
      {
        trois = calcul3();
      }
#pragma omp section
      {
        quatre = calcul4();
      }
    }
  }

  neuf = deux + trois + quatre;
  printf("neuf = %d\n", neuf);

  return 0;
}
