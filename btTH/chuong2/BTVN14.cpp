#include<stdio.h>
#include<conio.h>

void main(){
  const int GMC = 10;
  const int GDC = 24;
  const int MG = 17;	 // moc phan biet 2 menh  gia tien phai tra
  const int GT = 20000; //gia truoc 17h
  const long GS = 45000; // gia sau 17h
  int gioVao, phutVao, gioRa, phutRa, gioTrc, phutTrc, gioSau, phutSau, tongH, tongM;
  long tongTien;

  printf("Tinh tien karaoke\n");
  do {
    printf("=============================\n");
    printf("Gio vao(gom ca gio va phut cach nhau boi dau cach): \n");
    scanf("%d%d", &gioVao, &phutVao);
    printf("Gio ra(gom ca gio va phut cach nhau boi dau cach): \n");
    scanf("%d%d", &gioRa, &phutRa);
  } while(gioVao>24 || gioVao<1 || phutVao>59 || phutVao<0 || gioRa<1 || gioRa>24 || phutRa<0 || phutRa>59); //dieu kien nhap
//Xu li tinh tien
  if (gioVao<GMC || gioVao>GDC) {
    printf("Quan da dong cua\n");
  }else{
    if (gioVao<MG && phutVao>=0 && gioRa>=MG && phutRa > 0){
      //Xu ly thoi gian truoc 17h
      gioTrc = (MG-1) - gioVao;
      phutTrc = 60- phutVao;
      //Xu ly thoi gian sau 17h
      gioSau = gioRa - MG;
      phutSau = phutRa;
      tongTien = (gioTrc+(float)phutTrc/60)*GT + (gioSau+(float)phutSau/60)*GS;
    }else{
      if (phutRa<phutVao) {
        phutRa+=60;
        gioRa-=1;
      }
      tongH = gioRa-gioVao;
      tongM = phutRa-phutVao;
      if (gioVao>=GMC && gioRa<=MG) {
        tongTien = (tongH + (float)tongM/60)*GT;
      }else{
        tongTien = (tongH + (float)tongM/60)*GS;
      }
    }
  }
  printf("Tien phai tra: %ld\n", tongTien);
  getch();
}
