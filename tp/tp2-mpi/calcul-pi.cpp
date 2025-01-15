#include <chrono>
#include <iostream>
#include "mpi.h"

inline double f(double x)
{
  return (4.0 / (1 + x * x));
}

int main(int argc, char **argv)
{
  MPI_Init(&argc, &argv);

  int i;
  const int N = 100000000;
  double pi = 0.0;
  double s = 1.0 / (double)N;

  int rank, size;
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  MPI_Comm_size(MPI_COMM_WORLD, &size);

  // Calculer le pi tel que chaque processus parcours N/size iterations de la boucle. A savoir:
  // P0: (0...N/size - 1)
  // P1: (N/size ... 2N/size - 1), etc.
  // A FAIRE ...

  // Afficher la valeur pi finale depuis le processus 0
  if (rank == 0) { printf("Pi: %lf\n", pi); }

  MPI_Finalize();
  return 0;
}
