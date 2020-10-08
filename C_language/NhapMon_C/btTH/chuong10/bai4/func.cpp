#include<stdio.h>
#include<string.h>
struct Taxi{
  char maSo[5];
  char hoTen[50];
  char diaChiDonKhach[100];
  int soKM;
  int soChoNgoi;
};
void nhapTT(Taxi &a);
void xuatTT(Taxi a);
int kiemTra_DiaDiemDonKhach(Taxi, char *diaChi);
char *inHoaChuDau(char *a);
char *xoaKhoangChan(char *a);
void swap(char &a, char &b);
void xuatChoNgoi(Taxi);
int tinhTienXe(Taxi);

void nhapTT(Taxi &a){
  FILE *f;
  f=fopen("text.txt", "rt");
  fgets(a.maSo, 6, f);
  fgets(a.hoTen, 51, f);
  fgets(a.diaChiDonKhach, 101, f);
  fscanf("%d", &a.soKM);
  fscanf("%d", &a.soChoNgoi);
  fclose(f);
}
void xuatTT(Taxi a){
  printf("Ma so: %s\n",a.maSo);
  printf("Ho ten tai xe: %s\n",a.hoTen);
  printf("Dia chi don khach: %s\n",a.diaChiDonKhach);
  printf("So km da chay: %d km\n",a.soKM);
  printf("So cho ngoi cua taxi: %d cho\n",a.soChoNgoi);
}
void swap(char &a, char &b){
  char t = a;
  a=b;
  b=t;
}
char *xoaKhoangChan(char *a){
  int len =strlen(a), d=0;
  for(int i=0; i<len;i++){
    if(a[i]!=32 || a[i]==32&&a[i+1]!=32&&a[0]!=32){
      swap(a[d++], a[i]);
    }
  }
  a[d] = '\0';
  return a;
}
char *inHoaChuDau(char *a){
  int len = strlen(a);
  for(int i = 0; i<len; i++){
    if(a[i]==32&&a[i+1]!=32){
      if(a[i]<=122||a[i]>=97){
        a[i]-=32;
      }
    }
  }
  return a;
}
int kiemTra_DiaDiemDonKhach(Taxi a, char *diaChi){
  int lenA = strlen(a.diaChiDonKhach), lenB = strlen(diaChi),da=0,db=0;
  whie(db<lenB&&da<lenA){
    if(diaChi[db++]==a.diaChiDonKhach[da++]){
      continue;
    }
    db=0;
  }
  if(db==lenB){
    return 1;
  }
  return 0;
}
void xuatChoNgoi(Taxi a){
  printf("\nxe co %d cho ngoi\n", a.soChoNgoi);
}

int tinhTienXe(Taxi a){
  int km = a.soKM;
  if(a.soChoNgoi==7){
    if(km>10){
      return 5*15+5*14+(km-10)*10;
    }else if(km>6){
      return 5*15+(km-5)*14;
    }else return km*15;
  }else if(a.soChoNgoi==4){
    if(km>10){
      return 5*12+5*11+(km-10)*9;
    }else if(km>6){
      return 5*12+(km-5)*11;
    }else return km*12;
  }else printf("\nInvalid\n");
}
