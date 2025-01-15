#include <cstdio>
#include "unistd.h"
#include "mpi.h"

int calcul2() { sleep(2); return 2; }

int calcul3() { sleep(3); return 3; }

int calcul4() { sleep(4); return 4; }

int main(int argc, char **argv)
{
  MPI_Init(&argc, &argv);
  int procid, nproc;

  MPI_Comm_rank(MPI_COMM_WORLD, &procid);
  MPI_Comm_size(MPI_COMM_WORLD, &nproc);

  printf("%d/%d\n", procid, nproc);

  int deux, trois, quatre, neuf;

  if (procid == 0) {
    deux = calcul2();
    MPI_Recv(&trois, 1, MPI_INT, 1, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
    printf("trois recu %d\n", trois);
    MPI_Recv(&quatre, 1, MPI_INT, 2, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
    printf("quatre recu %d\n", quatre);
    neuf = deux + trois + quatre;
    MPI_Send(&neuf, 1, MPI_INT, 1, 0, MPI_COMM_WORLD); 
    MPI_Send(&neuf, 1, MPI_INT, 2, 0, MPI_COMM_WORLD); 
  } else if (procid == 1) {
    trois = calcul3();
    MPI_Send(&trois, 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
    MPI_Recv(&neuf, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
  } else if (procid == 2) {
    quatre = calcul4();
    MPI_Send(&quatre, 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
    MPI_Recv(&neuf, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
  }

//  neuf = deux + trois + quatre;

  printf("neuf %d\n", neuf);

  MPI_Finalize();
  return 0;
}
