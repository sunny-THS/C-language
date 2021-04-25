#include "GraphColoring.h"

int main(int argc, char const *argv[]) {
  GraphColoring g;
  g.docFile("sn.txt");
  g.xuat();
  g.initMauDinh();
  g.xacDinhBacCacDinh();
  g.toMau();
  printf("\nKet qua: \n");
  g.showRes();
  return 0;
}
