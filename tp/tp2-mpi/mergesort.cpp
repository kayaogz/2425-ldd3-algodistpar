#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <chrono>
#include <mpi.h>

void checkSorted(const std::vector<double>&);
void merge(double*, const double*, const int, const double*, const int); 

void printUsage(int argc, char **argv)
{
  printf("Usage: %s [array-size]\n", argv[0]);
}

int N;
int rank, size;

int main(int argc, char ** argv)
{
  MPI_Init(&argc, &argv);
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  MPI_Comm_size(MPI_COMM_WORLD, &size);
  if (argc < 2) {
    if (rank == 0) { printUsage(argc, argv); }
    MPI_Finalize();
    return 0;
  }

  // Initialiser le sous-tableau appartenant au processus courant aleatoirement
  N = std::atoi(argv[1]);
  std::srand(std::time(0));
  std::vector<double> A(N);
  for (int i = 0; i < N; i++) { A[i] = std::rand() % 10000; } 

  // Trier le sous-tableaux
  std::sort(&A[0], &A[N]);

  // Fusionner les sous-tableaux de maniere arborescente et former le tableau trie dans le processus 0
  // A FAIRE ...
  
  // Verifier si le tableau final dans le processus 0 est trie
  if (rank == 0) { checkSorted(A); }
  MPI_Finalize();
  return 0;
}

void checkSorted(const std::vector<double> & A) {
  if (A.size() != N * size) {
    std::cout << "Ça ne marche pas; la taille de A n'est pas bonne ! :(" << std::endl;
    return;
  }
  for (int i = 1; i < A.size(); i++) {
    if (A[i] < A[i-1]) {
      std::cout << "Ça ne marche pas; A n'est pas trie! :(" << std::endl;
      return;
    }
  }
  std::cout << "Ça marche les cocos ! " << std::endl;
}

void merge(
    double *res,
    const double *tabA,
    const int sizeA,
    const double *tabB,
    const int sizeB)
{
  int i = 0, j = 0;
  while (i != sizeA && j != sizeB ) {
    if (tabA[i] < tabB[j]) {
      res[i+j] = tabA[i];
      i++;
    } else {
      res[i+j] = tabB[j];
      j++;
    }
  }
  if (i == sizeA) {
    for(; j < sizeB; j++) {
      res[i+j] = tabB[j];
    }
  } else {
    for(; i < sizeA; i++) {
      res[i+j] = tabA[i];
    }
  }
}
