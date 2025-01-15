/** Exercice Hello World
  * Compilation: mpic++ -O2 hello-world-ref.cpp -o hello-world
  * Execution (avec 7 processus): mpirun -np 7 ./hello-world
  */
#include <cstdio>
#include "mpi.h"

int main(int argc, char **argv)
{
  MPI_Init(&argc, &argv);
  int rank, size;
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  MPI_Comm_size(MPI_COMM_WORLD, &size);
  printf("Hello World du processus %d/%d\n", rank, size);
  MPI_Finalize();
  return 0;
}
