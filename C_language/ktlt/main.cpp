#include <stdio.h>
#include<math.h>
// nếu a = b = c = 0 thì pt vô số nghiệm
// nếu a = 0 thì pt có 1 nghiệm -c/b
// tìm delta
// nếu delta >0 thì pt có 2 nghiệm
// nếu delta <0 thì pt vô nghiệm
// nếu delta = 0 thì pt có 1 nghiệm duy nhất
void TinhPTBac2() {
  float a, b, c;
  float x1, x2, delta;
  printf("Nhap a, b, c: ");
  scanf("%f%f%f", &a, &b, &c);

  if ( a == 0) {
    x1 = -c / b;
    printf("pt co 1 nghiem %.2f", x1);
    return;
  }
  if (a == 0 && b == 0 && c == 0) {
    printf("pt vô số nghiệm \n");
    return;
  }

  delta = pow(b, 2.0) - 4 * a * c;
  if(delta != 0) {
    if(delta > 0) {
      x1 = (-b + sqrt(delta)) / (2 * a);
      x2 = (-b - sqrt(delta)) / (2 * a);
      printf("Pt co 2 nghiem:\nx= %.2f\nx= %.2f", x1, x2);
    } else {
      printf("Pt trinh vo nghiem");
    }
  } else {
    x1 = -b / (2 * a);
    printf("Pt co 1 nghiem duy nhat: %.2f", x1);
  }
}
int main () {
  TinhPTBac2();
  return 1;
}
