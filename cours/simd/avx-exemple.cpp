// Compilation: g++ -O2 avx-exemple.cpp -o avx-exemple -mavx2
// Execution: ./avx-exemple

#include <cstdio>
#include "immintrin.h"

int main()
{
  // Initialiser les tableaux x et y
  int N = 8;
  float x[8] = {0, 1, 2, 3, 4, 5, 6, 7};
  float y[8] = {2, 2, 2, 2, 2, 2, 2, 2};

  // Le but est de calculer z[i] = x[i] + y[i] d'un seul coup pour les 8 elements des tableaux avec instructions AVX
  float z[8];

  // Le code scalaire
//  for (int i = 0; i < l; i++) { z[i] = x[i] + y[i]; }

  // Faire pareil avec des instructions et des variables AVX2
  // A FAIRE ...
  __m256 vecx, vecy, vecz;
  for (int i = 0; i < N; i = i + 8)
  {
    vecx = _mm256_loadu_ps(&x[i]);
    vecy = _mm256_loadu_ps(&y[i]);
    vecz = _mm256_add_ps(vecx, vecy);
    //  vecz = _mm256_sub_ps(vecx, vecy);
    //  vecz = _mm256_mul_ps(vecx, vecy);
    //  vecz = _mm256_div_ps(vecx, vecy);
    _mm256_storeu_ps(&z[i], vecz);
  }

  // Afficher le resultat
  for (int i = 0; i < N; i++) { printf("%f ", z[i]); }
  printf("\n");

  return 0;
}
